#include "gameboard.h"

#include <QGraphicsGridLayout>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QGraphicsWidget>
#include <QLabel>
#include <QRandomGenerator>
#include <QTimer>

#include "agentgraphics.h"
#include "boardgraphics.h"
#include "gamegraphics.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
  QGraphicsScene *scene = new QGraphicsScene(this);

  m_layout_widget = new QGraphicsWidget();
  m_layout_widget->setZValue(1);

  m_game_container = new QGraphicsLinearLayout(Qt::Vertical);

  m_game_layout = new QGraphicsGridLayout();
  m_agents_layout = new QGraphicsLinearLayout(Qt::Horizontal);

  m_game_container->addItem(m_game_layout);
  m_game_container->addItem(m_agents_layout);

  m_layout_widget->setLayout(m_game_container);

  for (int i = 0; i < m_game_members.size(); ++i) {
    for (int j = 0; j < m_game_members[i].size(); ++j) {
      auto &cell = m_game_members[i][j];
      bool isEnemy = isEnemyWay(i, j);
      cell = new BoardGraphics(isEnemy, m_layout_widget);
      m_game_layout->addItem(cell, i, j, Qt::AlignCenter);
    }
  }

  QPainterPath enemyPath;
  m_enemies_path =
      scene->addPath(enemyPath, QPen(Qt::magenta, 2.0f, Qt::DashLine,
                                     Qt::PenCapStyle::RoundCap, Qt::RoundJoin));
  m_enemies_path->setZValue(2);

  m_gate_lbls = new QLabel[2];

  m_gate_lbls[0].setText("Enter");
  m_gate_lbls[1].setText("Exit");
  for (int i = 0; i < 2; i++) {
    QFont temp = m_gate_lbls[i].font();
    temp.setBold(true);
    temp.setPointSizeF(20.0f);
    m_gate_lbls[i].setFont(temp);
    m_gate_lbls[i].setAlignment(Qt::AlignHCenter);
  }

  auto *m_widget_proxy = new QGraphicsProxyWidget(m_layout_widget);
  m_widget_proxy->setWidget(&m_gate_lbls[0]);
  m_game_layout->addItem(m_widget_proxy, GAME_ROWS_COUNT, 0, Qt::AlignLeft);

  m_widget_proxy = new QGraphicsProxyWidget(m_layout_widget);
  m_widget_proxy->setWidget(&m_gate_lbls[1]);
  m_game_layout->addItem(m_widget_proxy, GAME_ROWS_COUNT,
                         GAME_COLUMNS_COUNT - 1, Qt::AlignRight);

  m_agents_layout->addStretch();
  for (auto &agent : m_agents) {
    agent = new AgentGraphics(m_layout_widget);
    agent->setPlayerType(GameResourceManager::getRandomAgent());
    m_agents_layout->addItem(agent);
  }
  m_agents_layout->addStretch();

  QTimer *enemies_timer = new QTimer(this);
  connect(enemies_timer, &QTimer::timeout, this, &GameBoard::updateEnemies);
  enemies_timer->setTimerType(Qt::CoarseTimer);
  enemies_timer->start(750);

  auto *m_elixir_proxy = new QGraphicsProxyWidget(m_layout_widget);
  m_elixir_label = new QLabel("Elixir: 0");
  m_elixir_proxy->setWidget(m_elixir_label);
  m_game_container->addItem(m_elixir_proxy);

  scene->addItem(m_layout_widget);

  setScene(scene);
}

GameBoard::~GameBoard() { delete[] m_gate_lbls; }

void GameBoard::resizeEvent(QResizeEvent *event) {
  QPainterPath path;
  auto &item0 = m_game_members[GAME_ROWS_COUNT - 1][0];
  QPointF start = item0->mapToScene((item0->boundingRect().bottomLeft() +
                                     item0->boundingRect().bottomRight()) /
                                    2);
  path.moveTo(start);

  auto &item1 = m_game_members[0][0];
  QPointF midl = item1->mapToScene(item1->boundingRect().center());
  path.lineTo(midl);

  auto &item2 = m_game_members[0][GAME_COLUMNS_COUNT - 1];
  QPointF midr = item2->mapToScene(item2->boundingRect().center());
  path.lineTo(midr);

  auto &item3 = m_game_members[GAME_ROWS_COUNT - 1][GAME_COLUMNS_COUNT - 1];
  QPointF end = item3->mapToScene((item3->boundingRect().bottomLeft() +
                                   item3->boundingRect().bottomRight()) /
                                  2);
  path.lineTo(end);
  m_enemies_path->setPath(path);

  QGraphicsView::resizeEvent(event);
}

bool GameBoard::isEnemyWay(int i, int j) {
  return !i || !j || j + 1 == GAME_COLUMNS_COUNT;
}

GameGraphics *GameBoard::mapEnemyFromIndex(int index) {
  if (index < GAME_ROWS_COUNT) {
    return m_game_members[GAME_ROWS_COUNT - index - 1][0];
  } else if (index < GAME_ROWS_COUNT + GAME_COLUMNS_COUNT - 1) {
    return m_game_members[0][index - GAME_ROWS_COUNT + 1];
  } else {
    index -= GAME_ROWS_COUNT + GAME_COLUMNS_COUNT - 2;
    return m_game_members[index][GAME_COLUMNS_COUNT - 1];
  }
}

void GameBoard::updateEnemies() {
  for (int &i : m_enemies) {
    auto *graphics = mapEnemyFromIndex(i);
    auto pastState = graphics->playerType();
    graphics->resetPlayerType();
    i++;
    if (i < GAME_ENEMY_PATH_LENGTH) {
      graphics = mapEnemyFromIndex(i);
      graphics->setPlayerType(pastState);
    }
  }
  if (timerCounter % 5 == 0) {
    m_enemies.push_front(0);
    auto *graphics = mapEnemyFromIndex(0);
    graphics->setPlayerType(GameResourceManager::getRandomEnemy());
  }
  m_enemies.removeAll(GAME_ENEMY_PATH_LENGTH);
  timerCounter = (timerCounter + 1) % 5;
}

#undef GAME_BOARD_SQUARE_WIDTH
#undef GAME_BOARD_BORDER_TICKNESS
