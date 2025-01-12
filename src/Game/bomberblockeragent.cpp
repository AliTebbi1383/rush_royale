#include "bomberblockeragent.h"

#include "QDebug"

BomberBlockerAgent::BomberBlockerAgent(QObject *parent)
    : BlockerAgent{parent} {}

void BomberBlockerAgent::do_work() {
  qDebug() << "The BomberBlockerAgent is doing his work";
}

AgentContext::AgentType BomberBlockerAgent::type() const {
  return AgentContext::BomberBlocker;
}
