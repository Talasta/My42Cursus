#include "Tilemap.hpp"

#include "Vars.hpp"

#include "Operations.hpp"

#include <fstream>


#define TILE_SIZE 32u
#define TILES_PER_LINE 16u


Tilemap::Tilemap()
{
    m_texture.loadFromFile("data/tilemap/tileset.png");

    std::ifstream file("data/tilemap/tilemap");
    std::string line;

    std::getline(file, line);

    unsigned int s = toNumber(line);

    m_vertices.resize(s * s * 4);
    m_vertices.setPrimitiveType(sf::Quads);

    unsigned int posX = 0, posY = 0, index = 0;

    for(std::string temp; std::getline(file, line); posY += TILE_SIZE)
    {
        for(unsigned int i = 0; i != line.size(); ++i)
        {
            if(line[i] != ',')
            {
                temp += line[i];
            }
            else
            {
                unsigned int nb = toNumber(temp);

                sf::Vector2f texCoords((nb & (TILES_PER_LINE - 1)) * TILE_SIZE, nb / TILES_PER_LINE * TILE_SIZE);
                sf::Vertex* quad = &(m_vertices[index]);

                quad[0].position = sf::Vector2f(posX, posY);
                quad[1].position = sf::Vector2f(posX + TILE_SIZE, posY);
                quad[2].position = sf::Vector2f(posX + TILE_SIZE, posY + TILE_SIZE);
                quad[3].position = sf::Vector2f(posX, posY + TILE_SIZE);

                quad[0].texCoords = texCoords;
                quad[1].texCoords = sf::Vector2f(texCoords.x + TILE_SIZE, texCoords.y);
                quad[2].texCoords = texCoords + sf::Vector2f(TILE_SIZE, TILE_SIZE);
                quad[3].texCoords = sf::Vector2f(texCoords.x, texCoords.y + TILE_SIZE);

                posX += TILE_SIZE;
                index += 4;
                temp.clear();
            }
        }
        posX = 0;
    }
}

void Tilemap::render() const
{
    window.draw(m_vertices, &m_texture);
}
