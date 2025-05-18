#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *horde[N];
    while (N-- > 0)
    {
        horde[N] = new Zombie(name );
        horde[N]->announce();
    }
    return (*horde);
}