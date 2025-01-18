#ifndef AGENTCONTEXT_H
#define AGENTCONTEXT_H

#include <gameresourcemanager.h>

#include <QObject>
#include <QPainter>

QT_FORWARD_DECLARE_CLASS(Agent)

#define agentContext AgentContext::instance()

struct MultiMapObject {
  std::list<Agent *> agents;
  int level = 1;
};

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

  Q_DISABLE_COPY(AgentContext)

  static AgentContext *instance();
  static AgentType pick_random();
  static bool is_valid_player(int type);
  static void paint_player(QPainter *painter, const QRectF &rect,
                           AgentType type);
  static QImage player_pixmap(AgentType type);
  static QByteArray serialize_agent_type(AgentType ptype);
  static AgentType deserialize_agent_type(const QByteArray &bytes);
  int level(AgentType type);
  Agent *addAgent(AgentType type);

  bool level_up(AgentType type);

 private:
  AgentContext();

  static AgentContext *m_instance;
  MultiMapObject m_agents_map[TrapBlocker + 1];

  static Agent *constructAgent(AgentType type, QObject *parent);
  static GameResourceManager::PlayerType parse_agent(
      AgentContext::AgentType type);
  static QString parse_agent_string(AgentContext::AgentType type);
};

#endif  // AGENTCONTEXT_H
