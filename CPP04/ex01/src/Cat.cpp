#include "../include/Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Cat assigned" << std::endl;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
    delete brain;
}
