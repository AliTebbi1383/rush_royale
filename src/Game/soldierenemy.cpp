#include "soldierenemy.h"

#include <QDebug>

SoldierEnemy::SoldierEnemy(QObject *parent) : Enemy{parent} {}

void SoldierEnemy::attack() {
  qDebug() << "Soldier Enemy with " << m_damage << " is damaging to agents... "
           << this->type();
}

void SoldierEnemy::setDamage(int new_damage) { m_damage = new_damage; }

int SoldierEnemy::getDamage() const { return m_damage; }
