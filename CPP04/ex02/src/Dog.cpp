#include "../include/Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other) {
    std::cout << "Dog copied" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        AAnimal::operator=(other);
        std::cout << "Dog assigned" << std::endl;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain() const {
    return brain;
}

Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
    delete brain;
}
