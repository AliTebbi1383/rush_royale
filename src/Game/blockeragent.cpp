#include "blockeragent.h"

#include <QDebug>

BlockerAgent::BlockerAgent(QObject *parent) : Agent{parent} {}

void BlockerAgent::attack() {
  this->do_work();
  qDebug() << "The Blocker Agent is attacking";
}
