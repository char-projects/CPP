#include "ClapTrap.hpp"

int main() {
    std::string enemy = "Voldemort";
    
    std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
    ClapTrap clap1("Harry"); // Hit points: 10, Energy Points: 10, Attack Damage: 0
    ClapTrap clap2(clap1); // Copy constructor
    ClapTrap clap3; // Default constructor
    clap3 = clap1; // Assignment operator

    std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
    clap1.attack(enemy); // Hit points: 10, Energy Points: 9, Attack Damage: 0
    clap1.takeDamage(5); // Hit points: 5, Energy Points: 9, Attack Damage: 0
    clap1.beRepaired(3); // Hit points: 8, Energy Points: 8, Attack Damage: 0

    std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
    clap1.takeDamage(9); // Hit points: 0, Energy Points: 8, Attack Damage: 0
	clap1.attack(enemy); // Cannot attack, hit points are 0
	clap1.beRepaired(5); // Cannot repair, hit points are 0
    std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
}