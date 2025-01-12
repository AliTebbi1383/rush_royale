#ifndef AGENTCONTEXT_H
#define AGENTCONTEXT_H

#include <QObject>
#include <unordered_map>

QT_FORWARD_DECLARE_CLASS(Agent)

#define agentContext AgentContext::instance()

class AgentContext : public QObject {
 public:
  enum AgentType {
    FirstStriker,
    EndStriker,
    RandomStriker,
    MaxHealthStriker,
    BomberBlocker,
    TrapBlocker,
  };
  Q_ENUM(AgentType);

  static AgentContext *instance();
  bool level_up(AgentType type);

 private:
  AgentContext();

  static AgentContext *m_instance;
  std::unordered_map<AgentType, Agent *> m_agents_map;
};

#endif  // AGENTCONTEXT_H
