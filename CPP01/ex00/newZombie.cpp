#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
    return (new Zombie(name)); // allocate on heap
}