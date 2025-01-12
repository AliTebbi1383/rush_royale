#include "boardgraphics.h"

#include <Logger.h>

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

#define GAME_BOARD_BORDER_TICKNESS 1.0f
#define GAME_BOARD_SQUARE_WIDTH 75.0f

BoardGraphics::BoardGraphics(bool enemy, QGraphicsItem *parent)
    : GameGraphics(parent), m_overDrop(false), m_enemy(enemy) {
  setBorderTickness(GAME_BOARD_BORDER_TICKNESS);
  setSquareWidth(GAME_BOARD_SQUARE_WIDTH);
  setBorderColor(enemy ? Qt::darkRed : Qt::darkGreen);
  setAcceptDrops(true);
}

void BoardGraphics::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget) {
  const QPixmap &bg =
      m_enemy ? aResourceManager->red_grass : aResourceManager->green_grass;
  painter->drawPixmap(
      boundingRect().marginsAdded(QMarginsF(0.5f, 0.5f, 0.5f, 0.5f)), bg,
      QRectF(QPointF(0.0f, 0.0f), bg.size()));
  if (m_overDrop) {
    painter->setPen(option->palette.color(QPalette::Text));
    painter->drawRoundedRect(boundingRect(), 0.2, 0.2, Qt::RelativeSize);
  }
  GameGraphics::paint(painter, option, widget);
}

void BoardGraphics::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
  if (!m_enemy && !hasPlayer() &&
      event->mimeData()->hasFormat("application/x-dnditemdata")) {
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
  auto playerType = GameResourceManager::deserializePlayerType(
      event->mimeData()->data("application/x-dnditemdata"));
  setPlayerType(playerType);
  qCDebug(gameLog) << "Agent by ID: " << playerType << ", Moved into board";
  m_overDrop = false;
  update();
}

#undef GAME_BOARD_BORDER_TICKNESS
#undef GAME_BOARD_SQUARE_WIDTH
