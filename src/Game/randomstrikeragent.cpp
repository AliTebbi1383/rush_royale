#include "randomstrikeragent.h"

#include <QDebug>

RandomStrikerAgent::RandomStrikerAgent(QObject *parent)
    : StrikerAgent{parent} {}

Enemy *RandomStrikerAgent::select_enemy() {
  qDebug() << "I am selected a Random one!";
  return nullptr;
}

AgentContext::AgentType RandomStrikerAgent::type() const {
  return AgentContext::RandomStriker;
}
