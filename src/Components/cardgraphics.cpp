#include "cardgraphics.h"

#include <Game/agentcontext.h>

#include <QGraphicsSceneMouseEvent>
#include <QPainter>

#define CARDS_BORDER_TICKNESS 1.5f
#define CARDS_SQUARE_WIDTH 90.0f

CardGraphics::CardGraphics(AgentContext::AgentType type, QGraphicsItem *parent)
    : AgentGraphics(parent) {
  setBorderColor(Qt::yellow);
  setBorderTickness(CARDS_BORDER_TICKNESS);
  setSquareWidth(CARDS_SQUARE_WIDTH);
  setPlayerType(type);
  setFont(QFont("Times New Roman", 14));
  this->isWantedPrintUpgrade = true;
  setAcceptedMouseButtons(Qt::LeftButton);
}

void CardGraphics::forceUpdate() { update(); }

void CardGraphics::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget) {
  GameGraphics::paint(painter, option, widget);

  QRectF brect = AgentGraphics::boundingRect();

  QString txt = QString("Level %1").arg(agentContext->level(playerType()));
  if (agentContext->level(playerType()) == 5) txt += "(MAX)";
  QFontMetrics metrics(painter->fontMetrics());
  QSize text_size = metrics.size(0, txt);

  painter->save();
  painter->setPen(Qt::yellow);
  painter->drawText((brect.bottomLeft() + brect.bottomRight()) / 2 +
                        QPointF(-text_size.width() / 2, 15.0f),
                    txt);
  painter->restore();
}

void CardGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  agentContext->level_up(playerType());
}

QRectF CardGraphics::boundingRect() const {
  QRectF rect = AgentGraphics::boundingRect();
  rect.setHeight(rect.height() + 30);
  return rect;
}

#undef CARDS_BORDER_TICKNESS
#undef CARDS_SQUARE_WIDTH
