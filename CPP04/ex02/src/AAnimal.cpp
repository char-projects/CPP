#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : type("Owl") {
    std::cout << "Animal created" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
    std::cout << "Animal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
    std::cout << "Animal copied" << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    type = other.type;
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

void AAnimal::makeSound() const {
    std::cout << "* High-pitched screeching sound *" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destroyed" << std::endl;
}
