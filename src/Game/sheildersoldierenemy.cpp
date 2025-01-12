#include "sheildersoldierenemy.h"

SheilderSoldierEnemy::SheilderSoldierEnemy(QObject *parent)
    : SoldierEnemy{parent} {
  this->setDamage(500);
}

EnemyContext::Type SheilderSoldierEnemy::type() const {
  return EnemyContext::SheilderSoldier;
}
