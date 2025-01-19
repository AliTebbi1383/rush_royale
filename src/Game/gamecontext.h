#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(QTimer)

#define gameContext GameContext::instance()

class AgentContext;

class GameContext : public QObject {
  Q_OBJECT
  Q_PROPERTY(size_t elixirs READ elixirs NOTIFY elixirsChanged)
 public:
  static GameContext* instance();
  Q_DISABLE_COPY(GameContext)

  void startContext(int interval);
  int getContextInterval() const;

  size_t elixirs() const;

  inline static const int maximum_elixirs = 10;
 signals:
  void elixirsChanged(size_t elixirs);

 private slots:
  void onTimerTicks();

 private:
  GameContext();
  friend class AgentContext;

  void setElixirs(size_t elixirs);

  QTimer* m_timer;
  size_t m_elixirs;
  static GameContext* m_instance;
};

#endif  // GAMECONTEXT_H
