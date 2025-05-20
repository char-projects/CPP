#include "Zombie.h"

int main() {
    Zombie	*horde;

    std::cout << "Creating a horde of 3 zombies..." << std::endl;
    horde = zombieHorde(3, "Zombie");
    for (int i = 2; i >= 0; i--) {
        std::cout << horde[i].getName() << " created" << std::endl;
    }
    for (int i = 2; i >= 0; i--) {
        horde[i].announce();
    }
    delete[] horde;

    std::cout << "Creating a horde of 5 zombies..." << std::endl;
    horde = zombieHorde(5, "Zombie");
    for (int i = 4; i >= 0; i--) {
        std::cout << horde[i].getName() << " created" << std::endl;
    }
    for (int i = 4; i >= 0; i--) {
        horde[i].announce();
    }
    delete[] horde;
}