#include "strikeragent.h"

#include <QDebug>

StrikerAgent::StrikerAgent(QObject* parent) : Agent{parent} {}

void StrikerAgent::attack() {
  Enemy* enemy = this->select_enemy();
  qDebug() << "Striker Agent is Attacking ...";
}
