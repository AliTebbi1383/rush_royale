#include "gamegraphics.h"

#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QPainter>

GameGraphics::GameGraphics(QGraphicsItem *parent)
    : QGraphicsWidget(parent), ptype(GameResourceManager::Dummy) {
  setAcceptedMouseButtons(Qt::LeftButton);
}

QRectF GameGraphics::boundingRect() const {
  return QRectF(0, 0, m_square_width, m_square_width);
}

void GameGraphics::setSquareWidth(qreal newWidth) {
  Q_ASSERT(newWidth >= 10.0f);
  if (m_square_width != newWidth) {
    m_square_width = newWidth;
    setPreferredSize(boundingRect().size());
    update();
  }
}

void GameGraphics::setBorderTickness(qreal newTickness) {
  Q_ASSERT(newTickness <= 5.0f && newTickness >= 0.5f);
  if (m_border_thickness != newTickness) {
    m_border_thickness = newTickness;
    update();
  }
}

void GameGraphics::resetPlayerType() {
  setPlayerType(GameResourceManager::Dummy);
}

void GameGraphics::setPlayerType(GameResourceManager::PlayerType newPtype) {
  if (ptype != newPtype) {
    ptype = newPtype;
    update();
  }
}

void GameGraphics::setBorderColor(const QColor &newColor) {
  if (m_border_color != newColor) {
    m_border_color = newColor;
    update();
  }
}

void GameGraphics::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget) {
  QGraphicsWidget::paint(painter, option, widget);

  float bm = 5.0f * m_border_thickness;
  QRectF rect = boundingRect().marginsRemoved(QMarginsF{bm, bm, bm, bm});

  if (hasPlayer()) {
    aResourceManager->paintImage(painter, rect, ptype);
  }

  QPen pen(m_border_color, m_border_thickness);
  painter->setPen(pen);
  painter->drawRect(rect);
}
