#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        std::string getType() const;
        virtual void makeSound() const; // Pure virtual function
        virtual ~Animal();
};

#endif