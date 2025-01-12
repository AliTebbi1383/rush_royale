#include "trapblockeragent.h"

#include <QDebug>

TrapBlockerAgent::TrapBlockerAgent(QObject *parent) : BlockerAgent{parent} {}

void TrapBlockerAgent::do_work() {
  qDebug() << "The TrapBlocker is doing his work";
}

AgentContext::AgentType TrapBlockerAgent::type() const {
  return AgentContext::TrapBlocker;
}
