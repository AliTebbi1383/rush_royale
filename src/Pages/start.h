#ifndef START_H
#define START_H

#include <QWidget>

namespace Ui {
class Start;
}

QT_FORWARD_DECLARE_CLASS(QGraphicsScene)

class Start : public QWidget {
  Q_OBJECT

 public:
  explicit Start(QWidget *parent = nullptr);
  ~Start();

 private:
  Ui::Start *ui;

 private slots:
  void LaunchGame();
};

#endif  // START_H
