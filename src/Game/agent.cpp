#include "agent.h"

#include <QDebug>

Agent::Agent(QObject *parent) : QObject{parent} {}

bool Agent::powerUp() { return agentContext->level_up(this->type()); }

bool Agent::merge(Agent *other) {
  auto type_me = this->type();
  auto type_other = other->type();

  if (type_me == type_other) {
    qDebug() << "The Merge state is occured between: " << type_me << " and "
             << type_other;
    return true;
  }
  return false;
}
