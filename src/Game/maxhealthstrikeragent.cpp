#include "maxhealthstrikeragent.h"

#include <QDebug>

MaxHealthStrikerAgent::MaxHealthStrikerAgent(QObject *parent)
    : StrikerAgent{parent} {}

Enemy *MaxHealthStrikerAgent::select_enemy() {
  qDebug() << "I am selected who has the max health!";
  return nullptr;
}

AgentContext::AgentType MaxHealthStrikerAgent::type() const {
  return AgentContext::MaxHealthStriker;
}
