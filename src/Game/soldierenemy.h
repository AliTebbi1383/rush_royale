#ifndef SOLDIERENEMY_H
#define SOLDIERENEMY_H

#include "enemy.h"

class SoldierEnemy : public Enemy {
  Q_OBJECT
 public:
  explicit SoldierEnemy(QObject *parent = nullptr);
  void attack() override;

 protected:
  void setDamage(int new_damage);
  int getDamage() const;

 private:
  int m_damage;
};

#endif  // SOLDIERENEMY_H
