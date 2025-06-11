#include "../include/Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other) {
    std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        AAnimal::operator=(other);
        std::cout << "Cat assigned" << std::endl;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

Brain *Cat::getBrain() const {
    return brain;
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
    delete brain;
}
