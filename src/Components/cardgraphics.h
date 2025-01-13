#ifndef CARDGRAPHICS_H
#define CARDGRAPHICS_H

#include "gamegraphics.h"

class CardGraphics : public GameGraphics {
  Q_OBJECT
 public:
  CardGraphics(const GameResourceManager::PlayerType &type,
               QGraphicsItem *parent = nullptr);

 protected:
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) override;
};

#endif  // CARDGRAPHICS_H
