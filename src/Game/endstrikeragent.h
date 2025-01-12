#ifndef ENDSTRIKERAGENT_H
#define ENDSTRIKERAGENT_H

#include "agentcontext.h"
#include "strikeragent.h"

class EndStrikerAgent : public StrikerAgent {
  Q_OBJECT
 public:
  explicit EndStrikerAgent(QObject* parent = nullptr);

  Enemy* select_enemy() override;

 protected:
  AgentContext::AgentType type() const override;
};

#endif  // ENDSTRIKERAGENT_H
