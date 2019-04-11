#ifndef COMPONENTRENDER_HPP
#define COMPONENTRENDER_HPP

#include "Component.hpp"

#include <SFML/Graphics/VertexArray.hpp>

class Render : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    Render(const std::string& filename, const sf::FloatRect& texCoords, unsigned char z);
    virtual void init(Entity* owner);

    virtual void receive(const Message& msg);

    void draw() const;

    const std::string& getFilename() const;
    void setTexture(sf::Texture* texture);

    unsigned char z() const;

    sf::Vector2f getApparentSize() const;

    void setTexCoords(const sf::Rect<unsigned int>& texCoords);
    void setTransparency(unsigned char alpha);



private:

    std::string m_filename;

    sf::VertexArray m_vertices;

    unsigned char m_z;

    sf::Texture* m_texture;

};

#endif
