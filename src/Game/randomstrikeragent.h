#ifndef RANDOMSTRIKERAGENT_H
#define RANDOMSTRIKERAGENT_H

#include "strikeragent.h"

class RandomStrikerAgent : public StrikerAgent {
  Q_OBJECT
 public:
  explicit RandomStrikerAgent(QObject* parent = nullptr);

  Enemy* select_enemy() override;

 protected:
  AgentContext::AgentType type() const override;
};

#endif  // RANDOMSTRIKERAGENT_H
