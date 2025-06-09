#include "../include/Animal.hpp"

Animal::Animal() : type("Owl") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Animal assignment operator called" << std::endl;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "* High-pitched screeching sound *" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}
