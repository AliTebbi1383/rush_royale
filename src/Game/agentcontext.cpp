#include "agentcontext.h"

#include <QByteArray>
#include <QDebug>
#include <QPainter>
#include <QRandomGenerator>

#include "bomberblockeragent.h"
#include "endstrikeragent.h"
#include "firststrikeragent.h"
#include "gameresourcemanager.h"
#include "maxhealthstrikeragent.h"
#include "randomstrikeragent.h"
#include "trapblockeragent.h"

AgentContext* AgentContext::m_instance = nullptr;

AgentContext* AgentContext::instance() {
  if (m_instance == nullptr) {
    m_instance = new AgentContext();
  }
  return m_instance;
}

bool AgentContext::is_valid_player(int type) {
  return type >= 0 && type <= TrapBlocker;
}

void AgentContext::paint_player(QPainter* painter, const QRectF& rect,
                                AgentType type) {
  GameResourceManager::PlayerType ptype = parse_agent(type);
  QString text = parse_agent_string(type);
  aResourceManager->paintImage(painter, rect, ptype);

  painter->save();

  auto font_metrics = painter->fontMetrics();
  QSize box_size = font_metrics.size(0, text);

  painter->setBrush(Qt::yellow);
  QPointF p = rect.topRight() - QPoint(box_size.width(), 0);
  painter->drawRoundedRect(QRectF(p, box_size), 5, 5);
  painter->setPen(Qt::black);
  painter->drawText(p + QPointF(0, box_size.height() / 2 + 5), text);
  painter->restore();
}

QImage AgentContext::player_pixmap(AgentType type) {
  return aResourceManager->pixmap(parse_agent(type));
}

QByteArray AgentContext::serialize_agent_type(AgentType ptype) {
  QByteArray res(reinterpret_cast<char*>(&ptype), sizeof(ptype));
  return res;
}

int AgentContext::level(AgentType type) { return m_agents_map[type].level; }

Agent* AgentContext::addAgent(AgentType type) {
  Agent* newAgent = constructAgent(type, this);
  if (newAgent == nullptr) {
    qCritical() << "The Agent is incorrectly resourced!";
    quick_exit(1);
  }
  m_agents_map[type].agents.push_back(newAgent);
  return newAgent;
}

AgentContext::AgentType AgentContext::deserialize_agent_type(
    const QByteArray& bytes) {
  AgentType p;
  memcpy(&p, bytes.constData(), sizeof(p));
  return p;
}

AgentContext::AgentType AgentContext::pick_random() {
  return static_cast<AgentType>(
      QRandomGenerator::securelySeeded().bounded(TrapBlocker + 1));
}

bool AgentContext::level_up(AgentType type) {
  qDebug() << "Leveling up: " << type << ", ...";
  return true;
}

AgentContext::AgentContext() : QObject(nullptr) {}

Agent* AgentContext::constructAgent(AgentType type, QObject* parent) {
  switch (type) {
    case FirstStriker:
      return new FirstStrikerAgent(parent);
    case EndStriker:
      return new EndStrikerAgent(parent);
    case RandomStriker:
      return new RandomStrikerAgent(parent);
    case MaxHealthStriker:
      return new MaxHealthStrikerAgent(parent);
    case BomberBlocker:
      return new BomberBlockerAgent(parent);
    case TrapBlocker:
      return new TrapBlockerAgent(parent);
    default:
      return nullptr;
  }
}

GameResourceManager::PlayerType AgentContext::parse_agent(
    AgentContext::AgentType type) {
  return type >= FirstStriker && type <= MaxHealthStriker
             ? GameResourceManager::Agent3
             : GameResourceManager::Agent1;
}

QString AgentContext::parse_agent_string(AgentType type) {
  switch (type) {
    case FirstStriker:
      return "First";
    case EndStriker:
      return "End";
    case RandomStriker:
      return "Random";
    case MaxHealthStriker:
      return "MaxHealth";
    case BomberBlocker:
      return "Bomber";
    case TrapBlocker:
      return "Trapper";
    default:
      return "";
  }
}
