#ifndef BOSSENEMY_H
#define BOSSENEMY_H

#include "enemy.h"

class BossEnemy : public Enemy {
  Q_OBJECT
 public:
  explicit BossEnemy(QObject *parent = nullptr);

  void attack() override;

 protected:
  virtual void do_work() = 0;
};

#endif  // BOSSENEMY_H
