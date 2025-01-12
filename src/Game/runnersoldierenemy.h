#ifndef RUNNERSOLDIERENEMY_H
#define RUNNERSOLDIERENEMY_H

#include "soldierenemy.h"

class RunnerSoldierEnemy : public SoldierEnemy {
  Q_OBJECT
 public:
  explicit RunnerSoldierEnemy(QObject *parent = nullptr);

 protected:
  EnemyContext::Type type() const override;
};

#endif  // RUNNERSOLDIERENEMY_H
