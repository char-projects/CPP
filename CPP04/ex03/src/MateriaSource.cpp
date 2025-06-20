#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        materias[i] = NULL;
    // std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
    for (int i = 0; i < 4; ++i) 
        materias[i] = other.materias[i];
    // std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other) {
    for (int i = 0; i < 4; ++i)
        materias[i] = other.materias[i];
    // std::cout << "MateriaSource assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete materias[i];
    // std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (!materias[i]) {
            materias[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (materias[i] && materias[i]->getType() == type) {
            return materias[i]->clone();
        }
    }
    return NULL;
}
