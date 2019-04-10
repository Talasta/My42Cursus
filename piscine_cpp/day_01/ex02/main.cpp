#include "ZombieEvent.hpp"

int     main(void) {

    ZombieEvent ze = ZombieEvent();

    ze.setZombieType("gros");

    Zombie*     z1 = ze.newZombie("Nouveau1");
    Zombie*     z2 = ze.newZombie("Nouveau2");

    ze.randomChump();
    ze.randomChump();
    ze.randomChump();

    ze.setZombieType("petit");

    ze.randomChump();
    ze.randomChump();
    z1->announce();
    z2->announce();

    delete z1;
    delete z2;

    return 0;
}
