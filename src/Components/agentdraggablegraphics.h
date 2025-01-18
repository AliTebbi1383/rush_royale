#ifndef AGENTDRAGGABLEGRAPHICS_H
#define AGENTDRAGGABLEGRAPHICS_H

#include <QObject>

#include "agentgraphics.h"

QT_FORWARD_DECLARE_CLASS(QGraphicsItem)
QT_FORWARD_DECLARE_CLASS(QGraphicsSceneMouseEvent)

class AgentDraggableGraphics : public AgentGraphics {
  Q_OBJECT
 public:
  AgentDraggableGraphics(QGraphicsItem *parent = nullptr);

 protected:
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif  // AGENTDRAGGABLEGRAPHICS_H
