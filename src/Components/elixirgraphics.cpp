#include "elixirgraphics.h"

#include <QPainter>
#include <QPropertyAnimation>

ElixirGraphics::ElixirGraphics(QGraphicsItem *parent)
    : QGraphicsWidget(parent),
      elixir_logo(":/assets/elixir.png"),
      numbers_font("Times New Roman", 24, 400),
      elixirs(0) {
  animation = new QPropertyAnimation(this, "elixirStep");
  animation->setStartValue(0.0f);
  animation->setEndValue(1.0f);
  animation->setDuration(3000);
}

ElixirGraphics::~ElixirGraphics() { delete animation; }

QRectF ElixirGraphics::boundingRect() const {
  return QRectF(0.0f, 0.0f, 90.0f, 90.0f);
}

void ElixirGraphics::updateElixir() {
  animation->setCurrentTime(0);

  elixirs++;
  update();
}

void ElixirGraphics::setElixirs(size_t new_elixirs) {
  if (new_elixirs != elixirs) {
    animation->start();
    elixirs = new_elixirs;
    update();
  }
}

void ElixirGraphics::incrementEixirs() { setElixirs(elixirs + 1); }

void ElixirGraphics::startAnimation() { animation->start(); }

void ElixirGraphics::setElixirStep(float new_elixir_step) {
  if (new_elixir_step != elixir_step) {
    elixir_step = new_elixir_step;
    update();
  }
}

void ElixirGraphics::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget) {
  QGraphicsWidget::paint(painter, option, widget);
  QRectF ellipse_rect = boundingRect().marginsRemoved(QMargins(5, 5, 5, 5));

  painter->save();
  painter->setRenderHint(QPainter::Antialiasing);

  painter->drawPixmap(boundingRect(), elixir_logo, elixir_logo.rect());
  painter->setBrush(Qt::NoBrush);
  painter->setPen(QPen(Qt::white, 3.2f));
  painter->drawArc(ellipse_rect, 0 * 16, elixir_step * 360 * 16);
  painter->setPen(Qt::black);

  QString txt;
  txt.setNum(elixirs);

  QFontMetrics metrics(numbers_font);
  QSize size = metrics.size(0, txt);

  painter->setFont(numbers_font);

  QPointF p = ellipse_rect.center();
  painter->drawText(p.x() - size.width() / 2, p.y() + size.height() / 2, txt);

  painter->restore();
}
