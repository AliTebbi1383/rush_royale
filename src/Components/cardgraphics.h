#ifndef CARDGRAPHICS_H
#define CARDGRAPHICS_H

#include "agentgraphics.h"

QT_FORWARD_DECLARE_CLASS(QGraphicsSceneMouseEvent)

class CardGraphics : public AgentGraphics {
  Q_OBJECT
 public:
  CardGraphics(AgentContext::AgentType type, QGraphicsItem *parent = nullptr);

 public slots:
  void forceUpdate();

 protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

 public:
  QRectF boundingRect() const override;
};

#endif  // CARDGRAPHICS_H
