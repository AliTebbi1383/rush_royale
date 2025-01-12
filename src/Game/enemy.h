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

 protected:
  friend class EnemyContext;

  void setId(quint16 new_id);
  virtual EnemyContext::Type type() const = 0;

 private:
  int health;
  int speed;
  int spawn_interval;
  int defense_interval;

  quint16 id;
};

#endif  // ENEMY_H
