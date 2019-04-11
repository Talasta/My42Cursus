#ifndef COMPONENTBOXCOLLISION_HPP
#define COMPONENTBOXCOLLISION_HPP

#include "Component.hpp"
#include <SFML/System/Vector2.hpp>

#include <lua.hpp>
#undef cast
#include <LuaBridge.h>

#include <SFML/Graphics/Rect.hpp>


class CollisionBox : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    CollisionBox(const sf::Vector2f& size, const luabridge::LuaRef& collision);
    virtual void init(Entity* owner);

    virtual void receive(const Message& msg);

    const sf::FloatRect& getBoxRect() const;
    Entity* getOwner() const;

    bool reactsOnCollision() const;
    void collision(Entity* collided);

    void setSize(const sf::Vector2<unsigned int>& size);


private:

    Entity* m_owner;

    sf::FloatRect m_boxRect;

    bool m_reactsOnCollision;

    luabridge::LuaRef m_collision;
};

#endif
