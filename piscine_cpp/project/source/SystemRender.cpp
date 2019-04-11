#include "SystemRender.hpp"

#include "Vars.hpp"


RenderSystem::~RenderSystem()
{
    for(sf::Texture* texture : m_textures)
    {
        delete texture;
    }
}

void RenderSystem::update()
{
    for(Render* render : m_renders)
    {
        render->draw();
    }

    for(Text* text : m_texts)
    {
        window.draw(*text);
    }
}

void RenderSystem::receive(const Message& msg)
{
    Render* render = (Render*)msg.number;
    float posY = msg.vector.y;

    for(unsigned int i = 0; i != m_renders.size(); ++i)
    {
        if(render == m_renders[i])
        {
            if((i != 0 && posY < m_pos[i-1]) || (i + 1 != m_renders.size() && posY > m_pos[i+1]))
            {
                m_renders.erase(m_renders.begin() + i);
                m_pos.erase(m_pos.begin() + i);

                for(i = 0; posY > m_pos[i] && i != m_renders.size(); ++i);

                m_renders.insert(m_renders.begin() + i, render);
                m_pos.insert(m_pos.begin() + i, posY);
            }
            else
            {
                m_pos[i] = posY;
            }

            break;
        }
    }
}

void RenderSystem::add(Entity* entity)
{
    Render* render = entity->getComponent<Render>();

    if(render)
    {
        Message msg(Message::MMove);
        msg.number = (unsigned int)render;
        msg.vector.y = entity->getPosition().y + render->z();

        m_renders.insert(m_renders.begin(), render);
        m_pos.insert(m_pos.begin(), msg.vector.y);

        receive(msg);

        const std::string& filename = render->getFilename();
        bool newTexture = true;
        for(unsigned int i = 0; i != m_filenames.size(); ++i)
        {
            if(filename == m_filenames[i])
            {
                render->setTexture(m_textures[i]);
                newTexture = false;
                break;
            }
        }
        if(newTexture)
        {
            m_filenames.push_back(filename);
            sf::Texture* texture = new sf::Texture;
            texture->loadFromFile("data/texture/" + filename + ".png");
            m_textures.push_back(texture);
            render->setTexture(texture);
        }
    }
    else if(entity->getComponent<Text>())
    {
        m_texts.push_back(entity->getComponent<Text>());
    }
}

void RenderSystem::remove(Entity* entity)
{
    Render* render = entity->getComponent<Render>();

    if(render)
    {
        for(unsigned int i = 0; i != m_renders.size(); ++i)
        {
            if(m_renders[i] == render)
            {
                m_pos.erase(m_pos.begin() + i);
                m_renders.erase(m_renders.begin() + i);
                break;
            }
        }
    }
    else if(entity->getComponent<Text>())
    {
        Text* text = entity->getComponent<Text>();
        for(unsigned int i = 0; i != m_texts.size(); ++i)
        {
            if(m_texts[i] == text)
            {
                m_texts.erase(m_texts.begin() + i);
                break;
            }
        }
    }
}
