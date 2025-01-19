#include "sheildersoldierenemy.h"

SheilderSoldierEnemy::SheilderSoldierEnemy(QObject *parent)
    : SoldierEnemy{parent} {
  this->setDamage(500);
  this->speed = 0.5f;
}

EnemyContext::EnemyType SheilderSoldierEnemy::type() const {
  return EnemyContext::SheilderSoldier;
}
