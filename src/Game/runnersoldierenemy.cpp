#include "runnersoldierenemy.h"

RunnerSoldierEnemy::RunnerSoldierEnemy(QObject *parent) : SoldierEnemy{parent} {
  this->setDamage(10);
  this->speed = 1;
}

EnemyContext::EnemyType RunnerSoldierEnemy::type() const {
  return EnemyContext::RunnerSoldier;
}
