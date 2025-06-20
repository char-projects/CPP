#include "../include/Animal.hpp"

Animal::Animal() : type("Owl") {
    std::cout << "Animal created" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copied" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

Animal &Animal::operator=(const Animal &other) {
    type = other.type;
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "* High-pitched screeching sound *" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}
