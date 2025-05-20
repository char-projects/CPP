#include "Zombie.h"
#include <sstream>

Zombie *zombieHorde( int N, std::string name )
{
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        std::ostringstream oss;
        oss << name << (N - i);
        horde[i].setName(oss.str());
    }
    return (horde);
}