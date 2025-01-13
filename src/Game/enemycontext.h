#ifndef ENEMYCONTEXT_H
#define ENEMYCONTEXT_H

#include <QObject>
QT_FORWARD_DECLARE_CLASS(Enemy)

#define enemyContext EnemyContext::instance()

class EnemyContext : public QObject {
  Q_OBJECT
 public:
  enum Type {
    FreezerBoss,
    EraserBoss,
    DisarmerBoss,
    RunnerSoldier,
    SheilderSoldier,
  };
  Q_ENUM(Type);

  Q_DISABLE_COPY(EnemyContext)
  static EnemyContext *instance();

  void add_enemy(Enemy *enemy);

 private:
  EnemyContext();
  static EnemyContext *m_instance;
  std::list<Enemy *> m_enemies;

  quint16 id_counter = 0;
};

#endif  // ENEMYCONTEXT_H
