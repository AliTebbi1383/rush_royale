#include "agentgraphics.h"

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

AgentGraphics::AgentGraphics(QGraphicsItem *parent) : GameGraphics(parent) {
  setBorderTickness(AGENTS_BORDER_TICKNESS);
  setSquareWidth(AGENTS_SQUARE_WIDTH);
  setBorderColor(Qt::blue);
  setCursor(Qt::OpenHandCursor);
  setAcceptedMouseButtons(Qt::LeftButton);
}

void AgentGraphics::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  setCursor(Qt::OpenHandCursor);
}

void AgentGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (hasPlayer()) {
    setCursor(Qt::ClosedHandCursor);
  }
}

void AgentGraphics::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  QLineF screenMouseLine(event->screenPos(),
                         event->buttonDownScenePos(Qt::LeftButton));
  if (screenMouseLine.length() < QApplication::startDragDistance()) return;

  if (hasPlayer()) {
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData();

    drag->setHotSpot(QPoint(20, 20));

    QImage img = aResourceManager->pixmap(playerType());
    drag->setPixmap(QPixmap::fromImage(img).scaled(QSize(50, 50)));
    drag->setMimeData(mime);

    mime->setData("application/x-dnditemdata",
                  GameResourceManager::serializePlayerType(playerType()));

    Qt::DropAction action = drag->exec();
    if (action & Qt::DropAction::MoveAction) {
      setPlayerType(GameResourceManager::getRandomAgent());
    }
    setCursor(Qt::OpenHandCursor);
  }
}

#undef AGENTS_BORDER_TICKNESS
#undef AGENTS_SQUARE_WIDTH
