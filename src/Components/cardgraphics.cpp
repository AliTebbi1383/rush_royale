#include "cardgraphics.h"

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
}

void CardGraphics::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget) {
  GameGraphics::paint(painter, option, widget);

  QRectF brect = this->boundingRect();

  QString txt = QString("Level %1").arg(agentContext->level(playerType()));

  QFontMetrics metrics(painter->fontMetrics());
  QSize text_size = metrics.size(0, txt);

  painter->save();
  painter->setPen(Qt::green);
  painter->drawText((brect.bottomLeft() + brect.bottomRight()) / 2 +
                        QPointF(-text_size.width() / 2, 15.0f),
                    txt);
  painter->restore();
}

#undef CARDS_BORDER_TICKNESS
#undef CARDS_SQUARE_WIDTH
