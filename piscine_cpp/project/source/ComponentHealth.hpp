#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "Component.hpp"


class Health : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    Health(unsigned int health);
    virtual void init(Entity* owner);

    virtual void receive(const Message& msg);

    int getHealth() const;
    unsigned int getBaseHealth() const;
    void setHealth(unsigned int health);


private:

    Entity* m_owner;

    int m_health;
    unsigned int m_baseHealth;

};


#endif
