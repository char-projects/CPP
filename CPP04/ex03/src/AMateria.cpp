#include "../include/AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) {
	this->type = type;
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & other) {
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria & AMateria::operator=(AMateria const & other) {
    if (this != &other) {
        type = other.type;
    }
    // std::cout << "AMateria assignment operator called" << std::endl;
    return *this;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}

AMateria::~AMateria() {
    // std::cout << "AMateria destructor called" << std::endl;
}
