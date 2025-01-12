#include "eraserbossenemy.h"

#include <QDebug>

EraserBossEnemy::EraserBossEnemy(QObject *parent) : BossEnemy{parent} {}

EnemyContext::Type EraserBossEnemy::type() const {
  return EnemyContext::EraserBoss;
}

void EraserBossEnemy::do_work() {
  qDebug() << "Eraser Boss enemy is erasing now ...";
}
