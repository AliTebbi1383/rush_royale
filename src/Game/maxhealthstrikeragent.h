#ifndef MAXHEALTHSTRIKERAGENT_H
#define MAXHEALTHSTRIKERAGENT_H

#include "strikeragent.h"

class MaxHealthStrikerAgent : public StrikerAgent {
  Q_OBJECT
 public:
  explicit MaxHealthStrikerAgent(QObject* parent = nullptr);

  Enemy* select_enemy() override;

 protected:
  AgentContext::AgentType type() const override;
};

#endif  // MAXHEALTHSTRIKERAGENT_H
