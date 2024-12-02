#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>

#define AGENTS_COUNT 4
#define GAME_COLUMNS_COUNT 6
#define GAME_ROWS_COUNT 5

QT_FORWARD_DECLARE_CLASS(GameGraphics)

QT_FORWARD_DECLARE_CLASS(QGraphicsWidget)
QT_FORWARD_DECLARE_CLASS(QGraphicsLinearLayout)
QT_FORWARD_DECLARE_CLASS(QGraphicsGridLayout)
QT_FORWARD_DECLARE_CLASS(QLabel)

class GameBoard : public QGraphicsView {
  using GameBoardArray =
      std::array<std::array<GameGraphics *, GAME_COLUMNS_COUNT>,
                 GAME_ROWS_COUNT>;
  using AgentsDeckArray = std::array<GameGraphics *, AGENTS_COUNT>;

  Q_OBJECT
 public:
  GameBoard(QWidget *parent = nullptr);
  ~GameBoard();

 protected:
  void resizeEvent(QResizeEvent *event) override;

 private:
  QGraphicsWidget *m_layout_widget;
  QGraphicsLinearLayout *m_game_container;
  QGraphicsLinearLayout *m_agents_layout;
  QGraphicsGridLayout *m_game_layout;
  QLabel *m_gate_lbls;
  AgentsDeckArray m_agents;
  GameBoardArray m_game_members;

  static bool isEnemyWay(int i,int j);
};

#endif  // GAMEBOARD_H
