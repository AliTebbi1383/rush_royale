#include "enemy.h"

Enemy::Enemy(QObject *parent) : QObject{parent} {}

void Enemy::setId(quint16 new_id) { id = new_id; }
