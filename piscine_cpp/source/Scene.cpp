#include "Scene.hpp"

#include "Vars.hpp"
#include "Operations.hpp"

#include <fstream>


Scene* currentScene;


void Scene::load(const char* filename)
{
    currentScene = this;

    std::ifstream file((std::string)"data/level/" + filename);
    std::string line, entityName, temp;
    unsigned int posX;

    for(bool step = 0; std::getline(file, line);)
    {
        for(unsigned int i = 0; i != line.size(); ++i)
        {
            if(line[i] != ' ')
            {
                temp += line[i];
            }
            else
            {
                if(step == 0)
                {
                    entityName = temp;
                    step = 1;
                }
                else if(step == 1)
                {
                    posX = toNumber(temp);
                }

                temp.clear();
            }
        }

        add(entityFactory->createEntity(entityName, sf::Vector2f(posX, toNumber(temp))));

        temp.clear();
        step = 0;
    }
}

Scene::~Scene()
{
    for(Entity* entity : m_entities)
    {
        delete entity;
    }
}

void Scene::add(Entity* entity)
{
    m_entities.push_back(entity);

    for(System* system : systems)
    {
        system->add(entity);
    }
}

void Scene::remove(Entity* entity)
{
    m_entitiesToRemove.push_back(entity);
}

void Scene::update()
{
    if(m_entitiesToRemove.size() != 0)
    {
        for(Entity* entity : m_entitiesToRemove)
        {
            for(unsigned int i = 0; i != m_entities.size(); ++i)
            {
                if(m_entities[i] == entity)
                {
                    m_entities.erase(m_entities.begin() + i);

                    for(System* system : systems)
                    {
                        system->remove(entity);
                    }

                    delete entity;

                    break;
                }
            }
        }

        m_entitiesToRemove.clear();
    }
}
