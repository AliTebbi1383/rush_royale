#ifndef FREEZERBOSSENEMY_H
#define FREEZERBOSSENEMY_H

#include "bossenemy.h"

class FreezerBossEnemy : public BossEnemy {
  Q_OBJECT
 public:
  explicit FreezerBossEnemy(QObject *parent = nullptr);

 protected:
  EnemyContext::Type type() const override;
  void do_work() override;
};

#endif  // FREEZERBOSSENEMY_H
