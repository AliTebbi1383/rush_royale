#include "agentgraphics.h"

AgentGraphics::AgentGraphics(QGraphicsItem *parent)
    : GameGraphics(parent), type(static_cast<AgentContext::AgentType>(-1)) {}

void AgentGraphics::setPlayerType(AgentContext::AgentType new_type) {
  if (new_type != type) {
    type = new_type;
    update();
  }
}

bool AgentGraphics::hasPlayer() const {
  return AgentContext::is_valid_player(type);
}

void AgentGraphics::resetPlayer() {
  setPlayerType(static_cast<AgentContext::AgentType>(-1));
}

void AgentGraphics::paintImage(QPainter *painter, const QRectF &rect) {
  if (AgentContext::is_valid_player(type)) {
    AgentContext::paint_player(painter, rect, type);
  }
}
