#ifndef FIRSTSTRIKERAGENT_H
#define FIRSTSTRIKERAGENT_H

#include "strikeragent.h"

class FirstStrikerAgent : public StrikerAgent {
  Q_OBJECT
 public:
  explicit FirstStrikerAgent(QObject* parent = nullptr);

  Enemy* select_enemy() override;
  AgentContext::AgentType type() const override;
};

#endif  // FIRSTSTRIKERAGENT_H
