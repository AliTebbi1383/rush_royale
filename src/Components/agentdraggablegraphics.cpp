#include "agentdraggablegraphics.h"

#include <QApplication>
#include <QCursor>
#include <QDrag>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QRandomGenerator>
#include <QTime>
#include <QWidget>

#define AGENTS_BORDER_TICKNESS 2.0f
#define AGENTS_SQUARE_WIDTH 100.0f

AgentDraggableGraphics::AgentDraggableGraphics(QGraphicsItem *parent)
    : AgentGraphics(parent) {
  setBorderTickness(AGENTS_BORDER_TICKNESS);
  setSquareWidth(AGENTS_SQUARE_WIDTH);
  setBorderColor(Qt::blue);
  setCursor(Qt::OpenHandCursor);
  setAcceptedMouseButtons(Qt::LeftButton);
}

void AgentDraggableGraphics::mouseReleaseEvent(
    QGraphicsSceneMouseEvent *event) {
  setCursor(Qt::OpenHandCursor);
}

void AgentDraggableGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (hasPlayer()) {
    setCursor(Qt::ClosedHandCursor);
  }
}

void AgentDraggableGraphics::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  QLineF screenMouseLine(event->screenPos(),
                         event->buttonDownScenePos(Qt::LeftButton));
  if (screenMouseLine.length() < QApplication::startDragDistance()) return;

  if (hasPlayer()) {
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData();

    QImage img = AgentContext::player_pixmap(type);
    QPixmap pix = QPixmap::fromImage(img);
    drag->setPixmap(pix.scaled(QSize(50, 50)));
    drag->setHotSpot(QPoint(20, 20));
    drag->setMimeData(mime);

    mime->setData("application/x-dnditemdata",
                  AgentContext::serialize_agent_type(playerType()));

    Qt::DropAction action = drag->exec();
    if (action & Qt::DropAction::MoveAction) {
      setPlayerType(AgentContext::pick_random());
    }
    setCursor(Qt::OpenHandCursor);
  }
}

#undef AGENTS_BORDER_TICKNESS
#undef AGENTS_SQUARE_WIDTH
