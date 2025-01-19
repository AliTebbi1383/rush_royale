#ifndef SHEILDERSOLDIERENEMY_H
#define SHEILDERSOLDIERENEMY_H

#include "soldierenemy.h"

class SheilderSoldierEnemy : public SoldierEnemy {
  Q_OBJECT
 public:
  explicit SheilderSoldierEnemy(QObject *parent = nullptr);

 protected:
  EnemyContext::EnemyType type() const override;
};

#endif  // SHEILDERSOLDIERENEMY_H
