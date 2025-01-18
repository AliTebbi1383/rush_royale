#include "boardgraphics.h"

#include <Game/agent.h>
#include <Game/agentcontext.h>

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

#define GAME_BOARD_BORDER_TICKNESS 1.0f
#define GAME_BOARD_SQUARE_WIDTH 75.0f

BoardGraphics::BoardGraphics(bool enemy, int loc_x, int loc_y,
                             QGraphicsItem *parent)
    : GameGraphics(parent),
      m_overDrop(false),
      m_enemy(enemy),
      agent(nullptr),
      loc_x(loc_x),
      loc_y(loc_y) {
  setBorderTickness(GAME_BOARD_BORDER_TICKNESS);
  setSquareWidth(GAME_BOARD_SQUARE_WIDTH);
  setBorderColor(enemy ? Qt::darkRed : Qt::darkGreen);
  setAcceptDrops(true);
}

void BoardGraphics::paintImage(QPainter *painter, const QRectF &rect) {
  if (hasPlayer()) {
    AgentContext::paint_player(painter, rect, agent->type());
  }
}

void BoardGraphics::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget) {
  const QPixmap &bg =
      m_enemy ? aResourceManager->red_grass : aResourceManager->green_grass;
  painter->drawPixmap(
      boundingRect().marginsAdded(QMarginsF(0.5f, 0.5f, 0.5f, 0.5f)), bg,
      QRectF(QPointF(0.0f, 0.0f), bg.size()));
  GameGraphics::paint(painter, option, widget);
  if (m_overDrop) {
    painter->setPen(Qt::white);
    painter->drawRoundedRect(boundingRect(), 0.2, 0.2, Qt::RelativeSize);
  }
}

void BoardGraphics::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
  if (!m_enemy && !hasPlayer() &&
      event->mimeData()->hasFormat("application/x-dnditemdata")) {
    auto playerType = AgentContext::deserialize_agent_type(
        event->mimeData()->data("application/x-dnditemdata"));
    event->setProposedAction(Qt::MoveAction);
    event->accept();
    m_overDrop = true;
    update();
  } else {
    event->ignore();
  }
}

void BoardGraphics::dragLeaveEvent(QGraphicsSceneDragDropEvent *event) {
  m_overDrop = false;
  update();
}

void BoardGraphics::dropEvent(QGraphicsSceneDragDropEvent *event) {
  auto playerType = AgentContext::deserialize_agent_type(
      event->mimeData()->data("application/x-dnditemdata"));
  emit playerAdded(loc_x, loc_y, playerType);
  agent = agentContext->addAgent(playerType);
  m_overDrop = false;
  update();
}

#undef GAME_BOARD_BORDER_TICKNESS
#undef GAME_BOARD_SQUARE_WIDTH
