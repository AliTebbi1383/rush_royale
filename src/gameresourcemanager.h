#ifndef GAMERESOURCEMANAGER_H
#define GAMERESOURCEMANAGER_H

#include <QHash>
#include <QImage>

#define aResourceManager GameResourceManager::instance()

QT_FORWARD_DECLARE_CLASS(QPainter)

class GameResourceManager {
 public:
  enum PlayerType { Agent1, Agent2, Agent3, Dummy, Enemy1 };
  static void init();
  Q_DISABLE_COPY(GameResourceManager);

  void paintImage(QPainter* painter, const QRectF& rect,
                   PlayerType ptype) const;
  QImage pixmap(PlayerType ptype) const;

  static PlayerType getRandomAgent();
  static inline bool isAgent(PlayerType ptype) { return ptype < Dummy; }
  static inline bool isEnemy(PlayerType ptype) { return ptype > Dummy; }
  static inline bool isInvalid(PlayerType ptype) { return ptype == Dummy; }
  static QByteArray serializePlayerType(PlayerType ptype);
  static PlayerType deserializePlayerType(const QByteArray& bytes);
  static GameResourceManager* instance();

 private:
  QHash<PlayerType, QImage> m_map;

  static GameResourceManager* manager;
  GameResourceManager() = default;
};

#endif  // GAMERESOURCEMANAGER_H
