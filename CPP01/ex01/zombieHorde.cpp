#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    while (N-- > 0)
    {
        Zombie* horde = new Zombie(name);
        horde->announce();
        delete horde;
    }
    return (NULL);
}