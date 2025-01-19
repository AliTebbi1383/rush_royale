#include "disarmerbossenemy.h"

#include <QDebug>

DisarmerBossEnemy::DisarmerBossEnemy(QObject *parent) : BossEnemy{parent} {}

EnemyContext::EnemyType DisarmerBossEnemy::type() const {
  return EnemyContext::DisarmerBoss;
}

void DisarmerBossEnemy::do_work() {
  qDebug() << "Disarmer Boss is disarming now...";
}
