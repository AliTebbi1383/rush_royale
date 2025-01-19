#include "agent.h"

#include <Logger.h>

#include <QDebug>
#include <QMetaEnum>

Agent::Agent(QObject *parent) : QObject{parent} {}

bool Agent::merge(Agent *other) {
  QMetaEnum meta_enum = QMetaEnum::fromType<AgentContext::AgentType>();
  auto type_me = meta_enum.valueToKey(this->type());
  auto type_other = meta_enum.valueToKey(other->type());

  if (type_me == type_other) {
    qCDebug(gameLog) << "The Merge state is occured between: " << type_me
                     << " and " << type_other;
    return true;
  }
  return false;
}

int Agent::level() const { return agentContext->level(this->type()); }
