#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <Game/agentcontext.h>

#include <QGraphicsView>

#define AGENTS_COUNT 4
#define GAME_COLUMNS_COUNT 6
#define GAME_ROWS_COUNT 5
#define GAME_ENEMY_PATH_LENGTH (GAME_COLUMNS_COUNT + 2 * GAME_ROWS_COUNT - 2)

QT_FORWARD_DECLARE_CLASS(BoardGraphics)
QT_FORWARD_DECLARE_CLASS(ElixirGraphics)

QT_FORWARD_DECLARE_CLASS(QGraphicsWidget)
QT_FORWARD_DECLARE_CLASS(QGraphicsLinearLayout)
QT_FORWARD_DECLARE_CLASS(QGraphicsGridLayout)
QT_FORWARD_DECLARE_CLASS(QGraphicsPixmapItem)
QT_FORWARD_DECLARE_CLASS(AgentDraggableGraphics)
QT_FORWARD_DECLARE_CLASS(QLabel)

class GameBoard : public QGraphicsView {
  using GameBoardArray =
      std::array<std::array<BoardGraphics *, GAME_COLUMNS_COUNT>,
                 GAME_ROWS_COUNT>;
  using AgentsDeckArray = std::array<AgentDraggableGraphics *, AGENTS_COUNT>;

  Q_OBJECT
 public:
  GameBoard(QWidget *parent = nullptr);
  ~GameBoard();

 protected:
  void resizeEvent(QResizeEvent *event) override;

 private slots:
  void playerAdded(int, int, AgentContext::AgentType);
  void onElixirChanged(size_t newElixir);

 private:
  QGraphicsWidget *m_layout_widget;
  QGraphicsLinearLayout *m_game_container;
  QGraphicsLinearLayout *m_agents_layout;
  QGraphicsLinearLayout *m_game_state_layout;
  QGraphicsGridLayout *m_game_layout;
  QGraphicsPathItem *m_enemies_path;
  ElixirGraphics *m_elixir_widget;
  QLabel *m_gate_lbls;
  AgentsDeckArray m_agents;
  GameBoardArray m_game_members;

  static bool isEnemyWay(int i, int j);
};

#endif  // GAMEBOARD_H
