#include "ComponentSpawner.hpp"

#include "Entity.hpp"

#include "Vars.hpp"


const Component::Type Spawner::s_type = Component::CSpawner;

Spawner::Spawner() : Component(Component::CSpawner)
{

}

Component* Spawner::getCopy() const
{
    return new Spawner;
}
