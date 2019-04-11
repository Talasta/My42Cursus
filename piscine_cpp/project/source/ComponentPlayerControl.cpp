#include "ComponentPlayerControl.hpp"

#include "Entity.hpp"
#include "Vars.hpp"

#include "StatePlay.hpp"
#include "StateDeadScreen.hpp"

#include "ComponentHealth.hpp"
#include "ComponentMove.hpp"
#include "ComponentRender.hpp"


const Component::Type PlayerControl::s_type = Component::CPlayerControl;

PlayerControl::PlayerControl() : Component(Component::CPlayerControl){

}

Component* PlayerControl::getCopy() const
{
    return new PlayerControl;
}

void PlayerControl::init(Entity* owner)
{
    m_owner = owner;

    sf::View view = window.getView();
    view.setCenter(m_owner->getPosition());
    window.setView(view);

    Message msg;
    msg.vector = view.getCenter() - sf::Vector2f(WINDOW_RATIO_X * 50, WINDOW_RATIO_Y * 50);
    systems[System::ui]->receive(msg);
}

void PlayerControl::receive(const Message& msg)
{
    if(msg.type == Message::MMove)
    {
        sf::View view = window.getView();

        sf::Vector2f viewCenter(view.getCenter());

        if(msg.vector.x != 0)
        {
            viewCenter.x = m_owner->getPosition().x;
            if(viewCenter.x - view.getSize().x / 2 < 0)
            {
                viewCenter.x = view.getSize().x / 2;
            }
            else if(viewCenter.x + view.getSize().x / 2 > 1024)
            {
                viewCenter.x = 1024 - view.getSize().x / 2;
            }
        }

        if(msg.vector.y != 0)
        {
            viewCenter.y = m_owner->getPosition().y;
            if(viewCenter.y - view.getSize().y / 2 < 0)
            {
                viewCenter.y = view.getSize().y / 2;
            }
            else if(viewCenter.y + view.getSize().y / 2 > 1024)
            {
                viewCenter.y = 1024 - view.getSize().y / 2;
            }
        }

        Message message;
        message.vector = viewCenter - sf::Vector2f(WINDOW_RATIO_X * 50, WINDOW_RATIO_Y * 50);
        systems[System::ui]->receive(message);

        view.setCenter(viewCenter);
        window.setView(view);
    }
    else if(msg.type == Message::MHit)
    {
        Message message(Message::MEventCallback);
        message.number = m_owner->getComponent<Health>()->getHealth();
        triggerEvent("playerHpChanged", message);

        systems[System::playerControl]->receive(msg);
    }
}
