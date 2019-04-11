#ifndef SYSTEMRENDER_HPP
#define SYSTEMRENDER_HPP

#include "System.hpp"

#include "ComponentRender.hpp"
#include "ComponentText.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class RenderSystem : public System{

public:

    ~RenderSystem();

    virtual void update();

    virtual void add(Entity* entity);
    virtual void remove(Entity* entity);

    virtual void receive(const Message& msg);




private:

    std::vector<Render*> m_renders;
    std::vector<float> m_pos;

    std::vector<sf::Texture*> m_textures;
    std::vector<std::string> m_filenames;

    std::vector<Text*> m_texts;





};

#endif
