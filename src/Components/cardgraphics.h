#ifndef CARDGRAPHICS_H
#define CARDGRAPHICS_H

#include "agentgraphics.h"

class CardGraphics : public AgentGraphics {
  Q_OBJECT
 public:
  CardGraphics(AgentContext::AgentType type, QGraphicsItem *parent = nullptr);

 protected:
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) override;
};

#endif  // CARDGRAPHICS_H
