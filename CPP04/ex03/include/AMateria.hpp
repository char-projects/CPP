#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
    protected:
	    std::string type;

    public:
        AMateria(std::string const & type);
        AMateria(AMateria const & other);
        AMateria & operator=(AMateria const & other);
        std::string const & getType() const; // Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        virtual ~AMateria();
};

#endif