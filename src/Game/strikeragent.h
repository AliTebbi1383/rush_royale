#ifndef STRIKERAGENT_H
#define STRIKERAGENT_H

#include "agent.h"

QT_FORWARD_DECLARE_CLASS(Enemy)

class StrikerAgent : public Agent {
  Q_OBJECT
 public:
  explicit StrikerAgent(QObject* parent = nullptr);

  void attack() override;

 protected:
  virtual Enemy* select_enemy() = 0;

 private:
  int damage_per_hit;
};

#endif  // STRIKERAGENT_H
