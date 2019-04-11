#include "Human.hpp"

int     main( void ) {

    Human   h = Human();

    h.action("melee", "maxime");
    h.action("ranged", "maxime");
    h.action("intimidating", "maxime");

    h.action("melee", "baptiste");

    return 0;
}
