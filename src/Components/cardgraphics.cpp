#include "cardgraphics.h"

#include <QPainter>

#define CARDS_BORDER_TICKNESS 1.5f
#define CARDS_SQUARE_WIDTH 100.0f

CardGraphics::CardGraphics(const GameResourceManager::PlayerType &type,
                           QGraphicsItem *parent)
    : GameGraphics(parent) {
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

  QString txt = "Level";

  QFontMetrics metrics(painter->fontMetrics());
  QSize text_size = metrics.size(0, txt);

  painter->save();
  painter->drawText((brect.bottomLeft() + brect.bottomRight()) / 2 +
                        QPointF(-text_size.width() / 2, 5.5f),
                    "Level");
  painter->restore();
}

#undef CARDS_BORDER_TICKNESS
#undef CARDS_SQUARE_WIDTH
