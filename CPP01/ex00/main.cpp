#include "Zombie.hpp"

int main() {
    Zombie* zombie = newZombie("Heap_Zombie");
    zombie->announce();
    delete zombie;    
    randomChump("Stack_Zombie");
}