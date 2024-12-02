#ifndef GAMEGRAPHICS_H
#define GAMEGRAPHICS_H

#include <QGraphicsWidget>
#include <gameresourcemanager.h>

class GameGraphics : public QGraphicsWidget {
  Q_OBJECT
  Q_PROPERTY(qreal squareWidth READ squareWidth WRITE setSquareWidth)
  Q_PROPERTY(qreal borderTickness READ borderTickness WRITE setBorderTickness)
  Q_PROPERTY(GameResourceManager::PlayerType playerType READ playerType WRITE setPlayerType RESET resetPlayerType)
  Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor)
 public:
  GameGraphics(QGraphicsItem *parent = nullptr);

  QRectF boundingRect() const override;

  qreal squareWidth() const { return this->m_square_width; }
  void setSquareWidth(qreal newWidth);

  qreal borderTickness() const { return this->m_border_thickness; }
  void setBorderTickness(qreal newTickness);

  GameResourceManager::PlayerType playerType() const { return this->ptype;}
  bool hasPlayer() const { return !GameResourceManager::isInvalid(ptype);}
  void resetPlayerType();
  void setPlayerType(GameResourceManager::PlayerType newPtype);

  QColor borderColor() const { return this->m_border_color; }
  void setBorderColor(const QColor &newColor);

 protected:
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

 private:
  GameResourceManager::PlayerType ptype;
  QColor m_border_color;
  qreal m_square_width, m_border_thickness;
};

#endif  // GAMEGRAPHICS_H
