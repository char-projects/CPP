#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::string enemy = "Voldemort";
    std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
    ClapTrap clap1("Harry"); // Hit points: 10, Energy Points: 9, Attack Damage: 0
    ScavTrap scav1("Ron"); // Hit points: 100, Energy Points: 50, Attack Damage: 20
    ClapTrap clap2(clap1); // Copy constructor
    ClapTrap clap3; // Default constructor
    clap3 = clap1; // Assignment operator

    std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
    clap1.attack(enemy); // Hit points: 10, Energy Points: 9, Attack Damage: 0
    scav1.attack(enemy); // Hit points: 100, Energy Points: 49, Attack Damage: 20

    std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
    clap1.takeDamage(5); // Hit points: 5, Energy Points: 9, Attack Damage: 0
    clap1.beRepaired(3); // Hit points: 8, Energy Points: 8, Attack Damage: 0
    clap1.takeDamage(9); // Hit points: 0, Energy Points: 8, Attack Damage: 0
    clap1.attack(enemy); // Cannot attack, hit points are 0
    clap1.beRepaired(5); // Cannot repair, hit points are 0

    std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
    scav1.guardGate(); // Hit points: 100, Energy Points: 49, Attack Damage: 20
    scav1.attack(enemy); // Hit points: 100, Energy Points: 48, Attack Damage: 20
    scav1.takeDamage(50); // Hit points: 50, Energy Points: 48, Attack Damage: 20
    scav1.beRepaired(20); // Hit points: 70, Energy Points: 47, Attack Damage: 20
    scav1.attack(enemy); // Hit points: 70, Energy Points: 46, Attack Damage: 20
    scav1.takeDamage(100); // Hit points: 0, Energy Points: 46, Attack Damage: 20
    scav1.beRepaired(50); // Cannot repair, hit points are 0
    scav1.attack(enemy); // Cannot attack, hit points are 0
    std::cout << "────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
}