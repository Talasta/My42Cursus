#include "Pony.hpp"
#include <iostream>
#include <string>

Pony::Pony(std::string name, int color) : _name(name), _color(color), _life(10) {
    std::cout << "Pony " << this->getName() << " constructed" << std::endl;
}

Pony::~Pony(void) {
    std::cout << "Pony " << this->getName() << " desctruted" << std::endl;
}

Pony            *Pony::ponyOnTheHeap(std::string name) {
    Pony*   pony = new Pony(name, 0xffffff);
    return pony;
}

Pony            Pony::ponyOnTheStack(std::string name) {
    Pony    pony = Pony(name, 0x000000);
    return pony;
}


void            Pony::eat(void) {
    this->setLife(this->getLife() == 10 ? this->getLife() : this->getLife() + 1);
}

int             Pony::alive(void) {
    if (this->getLife() <= 0)
        return 0;
    return 1;
}

void            Pony::takeDamage(int damage_pts) {
    this->setLife(this->getLife() - damage_pts);
}

void            Pony::dataPony(void) {
    std::cout << std::endl << "Pony data" << std::endl;
    std::cout << this->getName() << std::endl;
    if (this->getColor() == 0) {
        std::cout << "Black" << std::endl;
    } else if (this->getColor() == 0xffffff) {
        std::cout << "White" << std::endl;
    }
    std::cout << this->getLife() << std::endl << std::endl;
}

std::string     Pony::getName(void) { return (this->_name.empty() ? "NULL" :  this->_name); }
int             Pony::getColor(void) { return this->_color; }
int             Pony::getLife(void) { return this->_life; }
void            Pony::setLife(int n) { this->_life = n; }
