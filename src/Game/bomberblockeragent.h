#ifndef BOMBERBLOCKERAGENT_H
#define BOMBERBLOCKERAGENT_H

#include "blockeragent.h"

class BomberBlockerAgent : public BlockerAgent {
  Q_OBJECT
 public:
  explicit BomberBlockerAgent(QObject *parent = nullptr);

  void do_work() override;

 protected:
  AgentContext::AgentType type() const override;
};

#endif  // BOMBERBLOCKERAGENT_H
