#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "MessageHandler.hpp"

class Entity;

class Component : public MessageHandler{

public:

    enum Type : unsigned char { CAI = 0, CAnimation, CCollisionBox, CCollisionBoxPlayer, CHealth, CMove, CPlayerControl, CRender, CScript, CSpawner, CText, CTextUI, CTimer };

    virtual Component* getCopy() const = 0;

    virtual void init(Entity* owner);

    virtual void receive(const Message& msg);

    virtual ~Component();

    Type type() const;


protected:

    Component(Type componentType);


private:

    Type m_type;


};

#endif
