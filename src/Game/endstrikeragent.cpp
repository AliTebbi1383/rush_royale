#include "endstrikeragent.h"

#include <QDebug>

EndStrikerAgent::EndStrikerAgent(QObject *parent) : StrikerAgent(parent) {}

Enemy *EndStrikerAgent::select_enemy() {
  qDebug() << "I am selected the End one!";
  return nullptr;
}

AgentContext::AgentType EndStrikerAgent::type() const {
  return AgentContext::EndStriker;
}
