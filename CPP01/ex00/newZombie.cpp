#include "Zombie.h"

Zombie* newZombie( std::string name ) {
    return (new Zombie(name)); // allocate on heap
}