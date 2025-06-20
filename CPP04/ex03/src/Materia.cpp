#include "Materia.hpp"
#include <iostream>

Materia::Materia() : AMateria("Materia") {
    // std::cout << "Materia constructor called" << std::endl;
}

Materia::Materia(Materia const & other) : AMateria(other) {
    // std::cout << "Materia copy constructor called" << std::endl;
}

Materia & Materia::operator=(Materia const & other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    // std::cout << "Materia assignment operator called" << std::endl;
    return *this;
}

Materia::~Materia() {
    // std::cout << "Materia destructor called" << std::endl;
}

AMateria* Materia::clone() const {
    return new Materia(*this);
}

void Materia::use(ICharacter& target) {
    AMateria::use(target);
}
