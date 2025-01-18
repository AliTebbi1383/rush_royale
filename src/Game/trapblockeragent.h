#ifndef TRAPBLOCKERAGENT_H
#define TRAPBLOCKERAGENT_H

#include "blockeragent.h"

class TrapBlockerAgent : public BlockerAgent {
  Q_OBJECT
 public:
  explicit TrapBlockerAgent(QObject *parent = nullptr);

  void do_work() override;
  AgentContext::AgentType type() const override;
};

#endif  // TRAPBLOCKERAGENT_H
