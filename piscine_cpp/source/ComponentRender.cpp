#include "ComponentRender.hpp"

#include "Entity.hpp"

#include "GameStateManager.hpp"

#include "StatePlay.hpp"

#include "Vars.hpp"


const Component::Type Render::s_type = Component::CRender;

Render::Render(const std::string& filename, const sf::FloatRect& texCoords, unsigned char z) : Component(Component::CRender), m_filename(filename), m_z(z)
{
    m_vertices.resize(4);
    m_vertices.setPrimitiveType(sf::Quads);

    m_vertices[0] = sf::Vertex(sf::Vector2f(- texCoords.width / 2, - texCoords.height - z),
                               sf::Vector2f(texCoords.left, texCoords.top));

    m_vertices[1] = sf::Vertex(sf::Vector2f(texCoords.width / 2, - texCoords.height - z),
                               sf::Vector2f(texCoords.left + texCoords.width, texCoords.top));

    m_vertices[2] = sf::Vertex(sf::Vector2f(texCoords.width / 2, - z),
                               sf::Vector2f(texCoords.left + texCoords.width, texCoords.top + texCoords.height));

    m_vertices[3] = sf::Vertex(sf::Vector2f(- texCoords.width / 2, - z),
                               sf::Vector2f(texCoords.left, texCoords.top + texCoords.height));
}

void Render::init(Entity* owner)
{
    m_vertices[0].position += owner->getPosition();
    m_vertices[1].position += owner->getPosition();
    m_vertices[2].position += owner->getPosition();
    m_vertices[3].position += owner->getPosition();
}

Component* Render::getCopy() const
{
    return new Render(m_filename, sf::FloatRect(m_vertices[0].texCoords, m_vertices[2].texCoords), m_z);
}

void Render::receive(const Message& msg)
{
    if(msg.type == Message::MMove)
    {
        sf::Vector2f shift = msg.vector;

        m_vertices[0].position += shift;
        m_vertices[1].position += shift;
        m_vertices[2].position += shift;
        m_vertices[3].position += shift;

        if(msg.vector.y != 0)
        {
            Message message(Message::MMove);
            message.vector.y = m_vertices[2].position.y + m_z;
            message.number = (unsigned int)this;
            systems[System::render]->receive(message);
        }
    }
}

void Render::draw() const
{
    window.draw(m_vertices, m_texture);
}

const std::string& Render::getFilename() const
{
    return m_filename;
}

void Render::setTexture(sf::Texture* texture)
{
    m_texture = texture;
}

unsigned char Render::z() const
{
    return m_z;
}

sf::Vector2f Render::getApparentSize() const
{
    return m_vertices[2].position - m_vertices[0].position;
}

void Render::setTexCoords(const sf::Rect<unsigned int>& texCoords)
{
    m_vertices[0].texCoords = sf::Vector2f(texCoords.left, texCoords.top);
    m_vertices[1].texCoords = sf::Vector2f(texCoords.left + texCoords.width, texCoords.top);
    m_vertices[2].texCoords = sf::Vector2f(texCoords.left + texCoords.width, texCoords.top + texCoords.height);
    m_vertices[3].texCoords = sf::Vector2f(texCoords.left, texCoords.top + texCoords.height);
}

void Render::setTransparency(unsigned char alpha)
{
    for(unsigned char i = 0; i != 4; ++i)
    {
        m_vertices[i].color.a = alpha;
    }
}
