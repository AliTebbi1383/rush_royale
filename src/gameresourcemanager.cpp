#include "gameresourcemanager.h"

#include <QPainter>
#include <QRandomGenerator>

#define DECLARE_RESOURCE(m, e, r) m->m_map[e] = QImage(r)

void GameResourceManager::init() {
  manager = new GameResourceManager();
  // Agent Resources
  DECLARE_RESOURCE(manager, Agent1, ":/assets/agent.png");
  DECLARE_RESOURCE(manager, Agent2, ":/assets/agent2.png");
  DECLARE_RESOURCE(manager, Agent3, ":/assets/agent3.png");
  // Enemy Resources
  DECLARE_RESOURCE(manager, Enemy1, ":/assets/enemy.png");
  DECLARE_RESOURCE(manager, Enemy2, ":/assets/enemy2.png");
  DECLARE_RESOURCE(manager, Enemy3, ":/assets/enemy3.png");
  // Grasses
  manager->red_grass = QPixmap(":/assets/red_grass.jpg");
  manager->green_grass = QPixmap(":/assets/green_grass.jpg");
}

void GameResourceManager::paintImage(QPainter *painter, QRectF rect,
                                     PlayerType ptype) const {
  const QImage &img = m_map[ptype];
  if (isEnemy(ptype)) {
    rect = rect.marginsRemoved(QMarginsF{7.5, 0, 7.5, 15});
  }
  painter->drawImage(rect, img);
}

QImage GameResourceManager::pixmap(PlayerType ptype) const {
  return m_map[ptype];
}

GameResourceManager::PlayerType GameResourceManager::getRandomAgent() {
  return static_cast<PlayerType>(QRandomGenerator::global()->bounded(3));
}

GameResourceManager::PlayerType GameResourceManager::getRandomEnemy() {
  return static_cast<PlayerType>(
      QRandomGenerator::global()->bounded(Dummy + 1, Dummy + 4));
}

QByteArray GameResourceManager::serializePlayerType(PlayerType ptype) {
  QByteArray res(reinterpret_cast<char *>(&ptype), sizeof(ptype));
  return res;
}

GameResourceManager::PlayerType GameResourceManager::deserializePlayerType(
    const QByteArray &bytes) {
  PlayerType p;
  memcpy(&p, bytes.data(), sizeof(p));
  return p;
}

GameResourceManager *GameResourceManager::instance() {
  Q_ASSERT(manager);
  return manager;
}

GameResourceManager *GameResourceManager::manager = nullptr;

#undef DECLARE_RESOURCE
