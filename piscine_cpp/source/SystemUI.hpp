#ifndef SYSTEMUI_HPP
#define SYSTEMUI_HPP

#include "System.hpp"

#include "ComponentTextUI.hpp"

class UISystem : public System{

public:

    virtual void update();

    virtual void add(Entity* entity);

    virtual void remove(Entity* entity);

    virtual void receive(const Message& msg);


private:

    std::vector<sf::Text*> m_texts;
    std::vector<sf::Vector2f> m_textsPos;
};

#endif
