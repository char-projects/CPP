#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
    public:
        Character(std::string const & name);
        Character(Character const & other);
        Character & operator=(Character const & other);
        virtual ~Character();
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif
