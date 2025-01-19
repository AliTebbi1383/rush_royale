#include "gameboard.h"

#include <Game/gamecontext.h>
#include <Logger.h>

#include <QGraphicsGridLayout>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QGraphicsWidget>
#include <QLabel>
#include <QRandomGenerator>

#include "agentdraggablegraphics.h"
#include "boardgraphics.h"
#include "cardgraphics.h"
#include "elixirgraphics.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
  QGraphicsScene *scene = new QGraphicsScene(this);

  m_layout_widget = new QGraphicsWidget();
  m_layout_widget->setSizePolicy(
      QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
  m_layout_widget->setZValue(1);

  m_game_container = new QGraphicsLinearLayout(Qt::Vertical);
  m_game_layout = new QGraphicsGridLayout();
  m_agents_layout = new QGraphicsLinearLayout(Qt::Horizontal);

  m_game_container->addItem(m_game_layout);
  m_game_container->addItem(m_agents_layout);

  m_layout_widget->setLayout(m_game_container);

  for (int i = 0; i < m_game_members.size(); ++i) {
    for (int j = 0; j < m_game_members[i].size(); ++j) {
      bool isEnemy = isEnemyWay(i, j);
      if (isEnemy) {
        m_game_members[i][j] =
            new BoardGraphics(isEnemy, 0, 0, m_layout_widget);
      } else {
        m_game_members[i][j] =
            new BoardGraphics(isEnemy, i - 1, j - 1, m_layout_widget);
        connect(m_game_members[i][j], &BoardGraphics::playerAdded, this,
                &GameBoard::playerAdded);
      }
      m_game_layout->addItem(m_game_members[i][j], i, j, Qt::AlignCenter);
    }
  }

  m_game_container->setAlignment(m_game_layout, Qt::AlignVCenter);
  m_game_layout->setSizePolicy(
      QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  m_game_container->setAlignment(m_game_layout, Qt::AlignCenter);
  m_game_layout->setSpacing(10);

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
    agent = new AgentDraggableGraphics(m_layout_widget);
    agent->setPlayerType(AgentContext::pick_random());
    m_agents_layout->addItem(agent);
  }
  m_agents_layout->addStretch();

  m_game_state_layout = new QGraphicsLinearLayout();

  m_elixir_widget = new ElixirGraphics();
  m_game_state_layout->addItem(m_elixir_widget);
  m_elixir_widget->startAnimation();

  for (int i = 0; i <= AgentContext::TrapBlocker; ++i) {
    auto *item = new CardGraphics(static_cast<AgentContext::AgentType>(i),
                                  m_layout_widget);
    m_game_state_layout->addItem(item);
    connect(gameContext, SIGNAL(elixirsChanged(size_t)), item,
            SLOT(forceUpdate()));
  }

  m_game_container->addItem(m_game_state_layout);
  m_game_container->setAlignment(m_game_state_layout, Qt::AlignHCenter);
  m_game_state_layout->setSizePolicy(
      QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum));

  scene->addItem(m_layout_widget);

  gameContext->startContext(500);
  connect(gameContext, &GameContext::elixirsChanged, this,
          &GameBoard::onElixirChanged);

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

void GameBoard::playerAdded(int loc_x, int loc_y,
                            AgentContext::AgentType type) {
  qCDebug(gameLog) << "Agent by ID: " << type << ", Moved into board at: {"
                   << loc_x << "," << loc_y << "}";
}

void GameBoard::onElixirChanged(size_t newElixir) {
  m_elixir_widget->setElixirs(newElixir);
}

bool GameBoard::isEnemyWay(int i, int j) {
  return !i || !j || j + 1 == GAME_COLUMNS_COUNT;
}

#undef GAME_BOARD_SQUARE_WIDTH
#undef GAME_BOARD_BORDER_TICKNESS
