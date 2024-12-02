#ifndef BOARDGRAPHICS_H
#define BOARDGRAPHICS_H

#include "gamegraphics.h"

class BoardGraphics : public GameGraphics {
  Q_OBJECT
 public:
  BoardGraphics(bool enemy,QGraphicsItem *parent = nullptr);

 protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
  void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
  void dropEvent(QGraphicsSceneDragDropEvent *event) override;

 private:
  bool m_overDrop;
  const bool m_enemy;
};

#endif  // BOARDGRAPHICS_H
