#include "SystemUI.hpp"

#include "Vars.hpp"


void UISystem::update()
{
    for(sf::Text* text : m_texts)
    {
        window.draw(*text);
    }
}

void UISystem::add(Entity* entity)
{
    if(entity->getComponent<TextUI>())
    {
        m_texts.push_back(entity->getComponent<TextUI>());
        m_textsPos.push_back(entity->getPosition());
    }
}

void UISystem::remove(Entity* entity)
{
    if(entity->getComponent<TextUI>())
    {
        TextUI* text = entity->getComponent<TextUI>();
        for(unsigned int i = 0; i != m_texts.size(); ++i)
        {
            if(text == m_texts[i])
            {
                m_texts.erase(m_texts.begin() + i);
                m_textsPos.erase(m_textsPos.begin() + i);
                break;
            }
        }
    }
}

void UISystem::receive(const Message& msg)
{
    for(unsigned char i = 0; i != m_texts.size(); ++i)
    {
        m_texts[i]->setPosition(sf::Vector2f(m_textsPos[i].x * WINDOW_RATIO_X + msg.vector.x, m_textsPos[i].y * WINDOW_RATIO_Y + msg.vector.y));
    }
}
