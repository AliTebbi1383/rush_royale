#include "bossenemy.h"

#include <QDebug>

BossEnemy::BossEnemy(QObject *parent) : Enemy{parent} {}

void BossEnemy::attack() {
  this->do_work();
  qDebug() << "Boss Enemy is doing his work with type: " << this->type();
}
