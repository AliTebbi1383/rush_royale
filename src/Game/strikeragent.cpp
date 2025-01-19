#include "strikeragent.h"

#include <QDebug>

StrikerAgent::StrikerAgent(QObject* parent) : Agent{parent} {}

int StrikerAgent::getRealDamage() const {
  return std::pow(2, agentContext->level(this->type()) - 1) * damage_per_hit;
}

void StrikerAgent::attack() {
  Enemy* enemy = this->select_enemy();
  qDebug() << "Striker Agent is Attacking ...";
}
