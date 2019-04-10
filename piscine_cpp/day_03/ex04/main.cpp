#include "SuperTrap.hpp"

int main(void) {
    srand(time(NULL));
    std::cout << std::endl << "FragTrap TEST:" << std::endl;

    FragTrap f1("H3N4");
    FragTrap f2("C2O1");
    FragTrap f3(f2);
    FragTrap f4;
    f4 = f3;

    f1.rangedAttack("C2O1");
    f2.takeDamage(70);
    f1.meleeAttack("H12");
    f3.takeDamage(42);
    f2.beRepaired(43);
    f1.vaulthunter_dot_exe("C2O1");
    f1.vaulthunter_dot_exe("C2O1");
    f1.vaulthunter_dot_exe("C2O1");
    f1.vaulthunter_dot_exe("C2O1");
    f1.vaulthunter_dot_exe("C2O1");

    std::cout << std::endl << std::endl << "ScavTrap TEST:" << std::endl;

    ScavTrap s1("Scav_1");
    ScavTrap s2("Scav_2_reloaded");
    ScavTrap s3(s2);
    ScavTrap s4;
    s4 = s3;

    s1.rangedAttack("C2O1");
    s2.takeDamage(42);
    s1.meleeAttack("H12");
    s3.takeDamage(42);
    s2.beRepaired(43);
    s1.challengeNewcomer();
    s1.challengeNewcomer();
    s1.challengeNewcomer();
    s1.challengeNewcomer();
    s1.challengeNewcomer();

    std::cout << std::endl << std::endl << "NinjaTrap TEST:" << std::endl;

    NinjaTrap n1("Niinja_1");

    n1.rangedAttack("C2O1");
    n1.takeDamage(42);
    n1.meleeAttack("H12");
    n1.takeDamage(42);
    n1.beRepaired(43);
    n1.ninjaShoebox(s2);
    n1.ninjaShoebox(n1);
    n1.ninjaShoebox(f1);
    n1.ninjaShoebox(f2);

    std::cout << std::endl;

    std::cout << std::endl << std::endl << "SuperTrap TEST:" << std::endl;

    SuperTrap su1("S22-33");

    su1.rangedAttack("C2O1");
    su1.takeDamage(42);
    su1.meleeAttack("H12");
    su1.takeDamage(42);
    su1.beRepaired(43);
    su1.vaulthunter_dot_exe("C2O1");
    su1.vaulthunter_dot_exe("C2O1");
    su1.ninjaShoebox(s2);
    su1.ninjaShoebox(f1);

    std::cout << std::endl;

    return 0;
}
