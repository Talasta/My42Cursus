#ifndef COMPONENTSPAWNER_HPP
#define COMPONENTSPAWNER_HPP

#include "Component.hpp"

class Spawner : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    Spawner();

};

#endif
