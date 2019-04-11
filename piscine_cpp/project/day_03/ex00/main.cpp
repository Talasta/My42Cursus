#include "FragTrap.hpp"

int main(void) {
    srand(time(NULL));

    std::cout << std::endl << "FragTrap TEST:" << std::endl;

    FragTrap f1("H3N4");
    FragTrap f2("C2O1");
    FragTrap f3(f2);
    FragTrap f4;
    f4 = f3;

    f1.rangedAttack("C2O1");
    f2.takeDamage(42);
    f1.meleeAttack("H12");
    f3.takeDamage(4242);
    f2.beRepaired(43);
    f1.vaulthunter_dot_exe("C2O1");
    f1.vaulthunter_dot_exe("C2O1");
    f1.vaulthunter_dot_exe("C2O1");
    f1.vaulthunter_dot_exe("C2O1");
    f1.vaulthunter_dot_exe("C2O1");

    std::cout << std::endl;
    
    return 0;
}
