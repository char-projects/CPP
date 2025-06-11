#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {
    protected:
        std::string type;
        
    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &other);
        std::string getType() const;
        virtual void makeSound() const; // Pure virtual function
        virtual ~AAnimal();
};

#endif