#ifndef ERASERBOSSENEMY_H
#define ERASERBOSSENEMY_H

#include "bossenemy.h"

class EraserBossEnemy : public BossEnemy {
  Q_OBJECT
 public:
  explicit EraserBossEnemy(QObject *parent = nullptr);

 protected:
  EnemyContext::Type type() const override;
  void do_work() override;
};

#endif  // ERASERBOSSENEMY_H
