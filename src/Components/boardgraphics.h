#ifndef BOARDGRAPHICS_H
#define BOARDGRAPHICS_H

#include <Game/agentcontext.h>

#include "gamegraphics.h"

QT_FORWARD_DECLARE_CLASS(Agent)

class BoardGraphics : public GameGraphics {
  Q_OBJECT
 public:
  BoardGraphics(bool enemy, int loc_x, int loc_y,
                QGraphicsItem *parent = nullptr);

 signals:
  void playerAdded(int, int, AgentContext::AgentType);

 protected:
  void paintImage(QPainter *painter, const QRectF &rect) override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
  void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
  void dropEvent(QGraphicsSceneDragDropEvent *event) override;

 private:
  bool m_overDrop;
  const bool m_enemy;
  const int loc_x, loc_y;

  bool hasPlayer() const { return agent != nullptr; }

  Agent *agent;
};

#endif  // BOARDGRAPHICS_H
