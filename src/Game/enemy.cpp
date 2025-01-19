#include "enemy.h"

Enemy::Enemy(QObject *parent) : QObject{parent} {}

float Enemy::Speed() const { return speed; }
