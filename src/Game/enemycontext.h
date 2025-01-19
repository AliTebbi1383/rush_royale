#ifndef ENEMYCONTEXT_H
#define ENEMYCONTEXT_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(Enemy)
QT_FORWARD_DECLARE_CLASS(QGraphicsPixmapItem)

#define enemyContext EnemyContext::instance()

class EnemyContext : public QObject {
  Q_OBJECT
 public:
  enum EnemyType {
    FreezerBoss,
    EraserBoss,
    DisarmerBoss,
    RunnerSoldier,
    SheilderSoldier,
  };
  Q_ENUM(EnemyType)

  Q_DISABLE_COPY(EnemyContext)
  static EnemyContext *instance();

  Enemy *add_random_soldier(QGraphicsPixmapItem *item);
  Enemy *add_random_boss(QGraphicsPixmapItem *item);
  static QImage getPixmapFor(EnemyType type);

  std::list<std::pair<Enemy *, QGraphicsPixmapItem *>> m_enemies;

 private:
  EnemyContext();
  static EnemyContext *m_instance;

  quint16 id_counter = 0;

  static Enemy *construct(QObject *parent, EnemyType type);
};

#endif  // ENEMYCONTEXT_H
