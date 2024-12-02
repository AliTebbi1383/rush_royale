#include "gameboard.h"

#include <QGraphicsGridLayout>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QGraphicsWidget>
#include <QLabel>
#include <QRandomGenerator>

#include "agentgraphics.h"
#include "boardgraphics.h"
#include "gamegraphics.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
  QGraphicsScene *scene = new QGraphicsScene(this);

  m_layout_widget = new QGraphicsWidget();

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

  scene->addItem(m_layout_widget);

  setScene(scene);
}

GameBoard::~GameBoard() {}

void GameBoard::resizeEvent(QResizeEvent *event) {
  QGraphicsView::resizeEvent(event);
}

bool GameBoard::isEnemyWay(int i, int j) {
  return !i || !j || j + 1 == GAME_COLUMNS_COUNT;
}

#undef GAME_BOARD_SQUARE_WIDTH
#undef GAME_BOARD_BORDER_TICKNESS
