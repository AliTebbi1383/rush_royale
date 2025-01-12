#include "agentcontext.h"

#include <QDebug>

AgentContext* AgentContext::m_instance = nullptr;

AgentContext* AgentContext::instance() {
  if (m_instance == nullptr) m_instance = new AgentContext();
  return m_instance;
}

bool AgentContext::level_up(AgentType type) {
  qDebug() << "Leveling up: " << type << ", ...";
  return true;
}

AgentContext::AgentContext() : QObject(nullptr) {}
