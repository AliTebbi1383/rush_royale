#ifndef AGENT_H
#define AGENT_H

#include <QObject>

#include "agentcontext.h"

class Agent : public QObject {
  Q_OBJECT
 public:
  explicit Agent(QObject* parent = nullptr);

  int getSpeedLevel() const { return speed_level; }

  bool powerUp();
  bool merge(Agent* other);
  int level() const;

  virtual void attack() = 0;
  virtual AgentContext::AgentType type() const = 0;

 private:
  int speed_level;
};

#endif  // AGENT_H
