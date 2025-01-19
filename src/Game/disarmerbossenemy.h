#ifndef DISARMERBOSSENEMY_H
#define DISARMERBOSSENEMY_H

#include "bossenemy.h"

class DisarmerBossEnemy : public BossEnemy {
  Q_OBJECT
 public:
  explicit DisarmerBossEnemy(QObject *parent = nullptr);

 protected:
  EnemyContext::EnemyType type() const override;
  void do_work() override;
};

#endif  // DISARMERBOSSENEMY_H
