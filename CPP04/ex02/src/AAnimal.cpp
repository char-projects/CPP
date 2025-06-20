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

AAnimal::~AAnimal() {
    std::cout << "Animal destroyed" << std::endl;
}
