#include "gamecontext.h"

#include <QTimer>

GameContext::GameContext() : QObject{nullptr}, m_elixirs(0) {
  m_timer = new QTimer(this);
  m_timer->setTimerType(Qt::PreciseTimer);
  connect(m_timer, &QTimer::timeout, this, &GameContext::onTimerTicks);
}

void GameContext::setElixirs(size_t n_elixirs) {
  if (n_elixirs != m_elixirs) {
    emit elixirsChanged(n_elixirs);
    m_elixirs = n_elixirs;
  }
}

GameContext* GameContext::instance() {
  if (m_instance == nullptr) {
    m_instance = new GameContext;
  }
  return m_instance;
}

void GameContext::startContext(int interval) {
  Q_ASSERT(interval > 200);

  m_timer->setInterval(interval);
  m_timer->start();
}

int GameContext::getContextInterval() const { return m_timer->interval(); }

size_t GameContext::elixirs() const { return m_elixirs; }

void GameContext::onTimerTicks() {
  if (m_elixirs < maximum_elixirs) {
    m_elixirs = m_elixirs + 1;
    emit elixirsChanged(m_elixirs);
  }
}

GameContext* GameContext::m_instance = nullptr;
