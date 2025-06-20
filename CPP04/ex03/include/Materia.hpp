#ifndef MATERIA_HPP
#define MATERIA_HPP

#include "AMateria.hpp"

class Materia : public AMateria
{
    public:
        Materia();
        Materia(Materia const & other);
        Materia & operator=(Materia const & other);
        virtual ~Materia();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif
