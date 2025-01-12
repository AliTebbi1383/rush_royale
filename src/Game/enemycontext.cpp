#include "enemycontext.h"

#include <QDebug>

#include "enemy.h"

EnemyContext *EnemyContext::m_instance = nullptr;

EnemyContext *EnemyContext::instance() {
  if (m_instance == nullptr) {
    m_instance = new EnemyContext();
  }
  return m_instance;
}

void EnemyContext::add_enemy(Enemy *enemy) {
  enemy->setId(id_counter);
  m_enemies.push_back(enemy);
  qDebug() << "Enemy with Id : " << enemy->id << " is Added";
  id_counter++;
}

EnemyContext::EnemyContext() : QObject(nullptr) {}
