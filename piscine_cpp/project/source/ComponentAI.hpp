#ifndef COMPONENTAI_HPP
#define COMPONENTAI_HPP

#include <SFML/System/Vector2.hpp>

#include <lua.hpp>
#undef cast
#include <LuaBridge.h>

#include <vector>


struct Path{

    std::vector<sf::Vector2i> lines;

    float travelledDistance = 1;

    float counter = 0;
};


#include "Component.hpp"


class AI : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    AI(unsigned int attackDistance, const luabridge::LuaRef& attack);
    virtual void init(Entity* owner);

    virtual void receive(const Message& msg);

    unsigned int getAttackDistance() const;
    Path* getPath();
    bool getState() const;

    void setPath(Path* path);
    void setState(bool state);

    void attack(Entity* target);

    enum : bool { moving = 0, attacking };

private:

    Entity* m_owner;

    unsigned int m_attackDistance;
    luabridge::LuaRef m_attack;

    bool m_state = moving;

    Path* m_path;
};

#endif
