#include "freezerbossenemy.h"

#include <QDebug>

FreezerBossEnemy::FreezerBossEnemy(QObject *parent) : BossEnemy{parent} {}

EnemyContext::EnemyType FreezerBossEnemy::type() const {
  return EnemyContext::FreezerBoss;
}

void FreezerBossEnemy::do_work() { qDebug() << "Boss Freezing enemies"; }
