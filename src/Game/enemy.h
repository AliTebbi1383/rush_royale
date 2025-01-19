#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>

class EnemyContext;

#include "enemycontext.h"

class Enemy : public QObject {
  Q_OBJECT
 public:
  explicit Enemy(QObject *parent = nullptr);

  virtual void attack() = 0;

  float loc = 0.0f;

  float Speed() const;

 protected:
  friend class EnemyContext;

  virtual EnemyContext::EnemyType type() const = 0;

  int health;
  float speed;
  int spawn_interval;
  int defense_interval;
};

#endif  // ENEMY_H
