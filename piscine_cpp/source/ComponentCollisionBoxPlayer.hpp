#ifndef COMPONENTCOLLISIONBOXPLAYER_HPP
#define COMPONENTCOLLISIONBOXPLAYER_HPP

#include "Component.hpp"

#include <lua.hpp>
#undef cast
#include <LuaBridge.h>

#include <SFML/Graphics/Rect.hpp>


class CollisionBoxPlayer : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    CollisionBoxPlayer(const sf::Vector2f& size, const luabridge::LuaRef& collision);
    virtual void init(Entity* owner);

    const sf::FloatRect& getBoxRect() const;
    void collision(Entity* player);


private:

    Entity* m_owner;

    sf::FloatRect m_boxRect;

    luabridge::LuaRef m_collision;

};

#endif
