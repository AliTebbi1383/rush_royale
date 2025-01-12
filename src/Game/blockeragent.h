#ifndef BLOCKERAGENT_H
#define BLOCKERAGENT_H

#include "agent.h"

class BlockerAgent : public Agent {
  Q_OBJECT
 public:
  explicit BlockerAgent(QObject *parent = nullptr);

  void attack() override;

 protected:
  virtual void do_work() = 0;
};

#endif  // BLOCKERAGENT_H
