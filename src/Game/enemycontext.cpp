#include "enemycontext.h"

#include <Logger.h>
#include <gameresourcemanager.h>

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QMetaEnum>
#include <QRandomGenerator>

#include "disarmerbossenemy.h"
#include "enemy.h"
#include "eraserbossenemy.h"
#include "freezerbossenemy.h"
#include "runnersoldierenemy.h"
#include "sheildersoldierenemy.h"

EnemyContext *EnemyContext::m_instance = nullptr;

EnemyContext *EnemyContext::instance() {
  if (m_instance == nullptr) {
    m_instance = new EnemyContext();
  }
  return m_instance;
}

Enemy *EnemyContext::add_random_soldier(QGraphicsPixmapItem *item) {
  auto rv = static_cast<EnemyType>(QRandomGenerator::securelySeeded().bounded(
      RunnerSoldier, SheilderSoldier + 1));
  auto *enemy = construct(this, rv);
  item->setPixmap(
      QPixmap::fromImage(getPixmapFor(enemy->type())).scaled(64, 64));
  m_enemies.push_back(std::make_pair(enemy, item));
  QMetaEnum meta_enum = QMetaEnum::fromType<EnemyContext::EnemyType>();
  qCDebug(gameLog) << "Runner Enemy with type : "
                   << meta_enum.valueToKey(enemy->type()) << " is Added";
  id_counter++;
  return enemy;
}

Enemy *EnemyContext::add_random_boss(QGraphicsPixmapItem *item) {
  auto rv = static_cast<EnemyType>(QRandomGenerator::securelySeeded().bounded(
      FreezerBoss, DisarmerBoss + 1));
  auto *enemy = construct(this, rv);
  item->setPixmap(
      QPixmap::fromImage(getPixmapFor(enemy->type())).scaled(64, 64));
  m_enemies.push_back(std::make_pair(enemy, item));
  QMetaEnum meta_enum = QMetaEnum::fromType<EnemyContext::EnemyType>();
  qCDebug(gameLog) << "Boss Enemy with type : "
                   << meta_enum.valueToKey(enemy->type()) << " is Added";
  id_counter++;
  return enemy;
}

QImage EnemyContext::getPixmapFor(EnemyType type) {
  switch (type) {
    case EraserBoss:
    case FreezerBoss:
      return std::move(aResourceManager->pixmap(GameResourceManager::Enemy1));
    case DisarmerBoss:
      return std::move(aResourceManager->pixmap(GameResourceManager::Enemy2));
    case RunnerSoldier:
      return std::move(aResourceManager->pixmap(GameResourceManager::Enemy2));
    case SheilderSoldier:
      return std::move(aResourceManager->pixmap(GameResourceManager::Enemy3));
    default:
      return QImage();
  }
}

EnemyContext::EnemyContext() : QObject(nullptr) {}

Enemy *EnemyContext::construct(QObject *parent, EnemyType type) {
  switch (type) {
    case EraserBoss:
      return new EraserBossEnemy(parent);
    case FreezerBoss:
      return new FreezerBossEnemy(parent);
    case DisarmerBoss:
      return new DisarmerBossEnemy(parent);
    case RunnerSoldier:
      return new RunnerSoldierEnemy(parent);
    case SheilderSoldier:
      return new SheilderSoldierEnemy(parent);
    default:
      return nullptr;
  }
}
