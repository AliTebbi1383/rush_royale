#ifndef ELIXIRGRAPHICS_H
#define ELIXIRGRAPHICS_H

#include <QGraphicsWidget>
#include <QPixmap>

QT_FORWARD_DECLARE_CLASS(QPropertyAnimation)

class ElixirGraphics : public QGraphicsWidget {
  Q_OBJECT
  Q_PROPERTY(float elixirStep READ elixirStep WRITE setElixirStep)
 public:
  ElixirGraphics(QGraphicsItem *parent = nullptr);
  ~ElixirGraphics();

  QRectF boundingRect() const override;

  void updateElixir();
  void setElixirs(size_t new_elixirs);
  void incrementEixirs();
  void startAnimation();

 protected:
  void setElixirStep(float new_elixir_step);
  float elixirStep() const { return elixir_step; }

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

 private:
  size_t elixirs;
  float elixir_step;

  QPropertyAnimation *animation;
  const QPixmap elixir_logo;
  const QFont numbers_font;
};

#endif  // ELIXIRGRAPHICS_H
