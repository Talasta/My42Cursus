#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>

class Tilemap{

public:

    Tilemap();

    void render() const;


private:

    sf::VertexArray m_vertices;
    sf::Texture m_texture;
};

#endif
