#include "runnersoldierenemy.h"

RunnerSoldierEnemy::RunnerSoldierEnemy(QObject *parent) : SoldierEnemy{parent} {
  this->setDamage(10);
}

EnemyContext::Type RunnerSoldierEnemy::type() const {
  return EnemyContext::RunnerSoldier;
}
