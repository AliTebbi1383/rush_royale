#ifndef BLOCKERAGENT_H
#define BLOCKERAGENT_H

#include "agent.h"

class BlockerAgent : public Agent {
  Q_OBJECT
 public:
  explicit BlockerAgent(QObject *parent = nullptr);

  void attack() override;
  int getRealDeletedEnemiesCount() const;

 protected:
  virtual void do_work() = 0;

 private:
  int delete_enemies_count = 2;
};

#endif  // BLOCKERAGENT_H
