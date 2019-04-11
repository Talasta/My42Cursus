#ifndef COMPONENTPLAYERCONTROL_HPP
#define COMPONENTPLAYERCONTROL_HPP

#include "Component.hpp"

class PlayerControl : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    PlayerControl();
    virtual void init(Entity* owner);

    virtual void receive(const Message& msg);


private:

    Entity* m_owner;
};

#endif
