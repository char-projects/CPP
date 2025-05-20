#include "Zombie.h"

Zombie::Zombie() {
	this->name = "";
}

Zombie::Zombie(std::string name) : name(name) {
    std::cout << this->name << " created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << this->name << " destroyed" << std::endl;
}

void Zombie::setName( std::string name ) {
    this->name = name;
}

std::string Zombie::getName( void ) {
    return this->name;
}

void Zombie::announce( void ) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
