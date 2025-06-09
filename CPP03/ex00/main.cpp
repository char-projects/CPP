#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1("Voldemort");
    ClapTrap claptrap2(claptrap1); // Copy constructor
    ClapTrap claptrap3; // Default constructor
    claptrap3 = claptrap1; // Assignment operator

    claptrap1.attack("Harry"); // Hit points: 10, Energy Points: 9, Attack Damage: 0
    claptrap1.takeDamage(5); // Hit points: 5, Energy Points: 9, Attack Damage: 0
    claptrap1.beRepaired(3); // Hit points: 8, Energy Points: 8, Attack Damage: 0

    claptrap1.takeDamage(9); // Hit points: 0, Energy Points: 8, Attack Damage: 0
	claptrap1.attack("Harry"); // Cannot attack, hit points are 0
	claptrap1.beRepaired(5); // Cannot repair, hit points are 0

    return 0;
}