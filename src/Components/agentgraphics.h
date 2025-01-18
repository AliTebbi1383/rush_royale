#ifndef AGENTGRAPHICS_H
#define AGENTGRAPHICS_H

#include "Game/agentcontext.h"
#include "gamegraphics.h"

QT_FORWARD_DECLARE_CLASS(QPainter)

class AgentGraphics : public GameGraphics {
  Q_OBJECT
  Q_PROPERTY(
      AgentContext::AgentType playerType READ playerType WRITE setPlayerType)
 public:
  AgentGraphics(QGraphicsItem *parent);

  AgentContext::AgentType playerType() const { return type; }
  void setPlayerType(AgentContext::AgentType new_type);
  bool hasPlayer() const;
  void resetPlayer();

 protected:
  void paintImage(QPainter *painter, const QRectF &rect) override;
  AgentContext::AgentType type;
};

#endif  // AGENTGRAPHICS_H
