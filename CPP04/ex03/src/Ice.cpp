#include "../include/Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
    // std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const & other) : AMateria(other) {
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice & Ice::operator=(Ice const & other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    // std::cout << "Ice assignment operator called" << std::endl;
    return *this;
}

Ice::~Ice() {
    // std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    AMateria::use(target);
}
