#ifndef AGENT_H
#define AGENT_H

#include <QObject>
#include "agentcontext.h"

class Agent : public QObject
{
    Q_OBJECT
public:
    explicit Agent(QObject *parent = nullptr);

    int getNeededElixir() const{
        return needed_elixir;
    }
    int getSpeedLevel() const{
        return speed_level;
    }
    int getPowerLevel() const{
        return power_level;
    }

    bool powerUp();
    bool merge(Agent* other);

    virtual void attack() = 0;

protected:
    virtual AgentContext::AgentType type() const = 0;

private:
    int needed_elixir;
    int power_level;
    int speed_level;
};

#endif // AGENT_H
