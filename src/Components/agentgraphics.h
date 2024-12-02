#ifndef AGENTGRAPHICS_H
#define AGENTGRAPHICS_H

#include "gamegraphics.h"

class AgentGraphics : public GameGraphics {
  Q_OBJECT
 public:
  AgentGraphics(QGraphicsItem *parent = nullptr);

 protected:
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif  // AGENTGRAPHICS_H
