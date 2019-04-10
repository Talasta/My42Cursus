#ifndef SCENE_HPP
#define SCENE_HPP

#include "Entity.hpp"

class Scene{

public:

    void load(const char* scene);
    ~Scene();

    void add(Entity* entity);
    void remove(Entity* entity);

    void update();

private:

    std::vector<Entity*> m_entities;

    std::vector<Entity*> m_entitiesToRemove;
};

#endif
