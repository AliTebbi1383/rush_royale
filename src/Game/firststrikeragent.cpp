#include "firststrikeragent.h"

#include <QDebug>

FirstStrikerAgent::FirstStrikerAgent(QObject *parent) : StrikerAgent{parent} {}

Enemy *FirstStrikerAgent::select_enemy() {
  qDebug() << "I am selected the first one!";
  return nullptr;
}

AgentContext::AgentType FirstStrikerAgent::type() const {
  return AgentContext::FirstStriker;
}
