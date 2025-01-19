#ifndef GAMEGRAPHICS_H
#define GAMEGRAPHICS_H

#include <QGraphicsWidget>

class GameGraphics : public QGraphicsWidget {
  Q_OBJECT
  Q_PROPERTY(qreal squareWidth READ squareWidth WRITE setSquareWidth)
  Q_PROPERTY(qreal borderTickness READ borderTickness WRITE setBorderTickness)
  Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor)
 public:
  GameGraphics(QGraphicsItem *parent = nullptr);

  virtual QRectF boundingRect() const override;

  qreal squareWidth() const { return this->m_square_width; }
  void setSquareWidth(qreal newWidth);

  qreal borderTickness() const { return this->m_border_thickness; }
  void setBorderTickness(qreal newTickness);

  QColor borderColor() const { return this->m_border_color; }
  void setBorderColor(const QColor &newColor);

 protected:
  virtual void paintImage(QPainter *painter, const QRectF &rect);
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) override;

 private:
  QColor m_border_color;
  qreal m_square_width, m_border_thickness;
};

#endif  // GAMEGRAPHICS_H
