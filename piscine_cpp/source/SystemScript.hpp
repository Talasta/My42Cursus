#ifndef SYSTEMSCRIPT_HPP
#define SYSTEMSCRIPT_HPP

#include "System.hpp"
#include "ComponentScript.hpp"

class ScriptSystem : public System{

public:

    virtual void update();

    virtual void add(Entity* entity);
    virtual void remove(Entity* entity);

    virtual void receive(const Message& msg);


private:

    std::vector<Script*> m_activeScripts;
    std::vector<Script*> m_idleScripts;

};

#endif
