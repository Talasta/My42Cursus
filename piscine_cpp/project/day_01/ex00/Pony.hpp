
#include <string>

#ifndef PONY_HPP
# define PONY_HPP

class Pony {

public:

    static Pony     ponyOnTheStack(std::string);
    static Pony*    ponyOnTheHeap(std::string);

    ~Pony( void );

    void            eat(void);
    int             alive(void);
    void            takeDamage(int);
    void            dataPony(void);

    int             getLife(void);
    int             getColor(void);
    std::string     getName(void);

    void            setLife(int);

private:
    std::string     _name;
    int             _color;
    int             _life;

    Pony( std::string , int );

};

#endif
