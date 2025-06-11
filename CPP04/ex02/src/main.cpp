#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main() {
    std::cout << "─────────────────────────────────" << std::endl;
    std::cout << "Test 1:" << std::endl;
    std::cout << "─────────────────────────────────" << std::endl;
    const AAnimal* k = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << "─────────────────────────────────" << std::endl;
    std::cout << "Animal type: " << k->getType() << " " << std::endl << "Sound: ";
    k->makeSound();
    std::cout << "Animal type: " << j->getType() << " " << std::endl << "Sound: ";
    j->makeSound();
    std::cout << "Animal type: " << i->getType() << " " << std::endl << "Sound: ";
    i->makeSound();
    std::cout << "─────────────────────────────────" << std::endl;
    std::cout << "─────────────────────────────────" << std::endl;
    delete k;
    delete j; //should not create a leak
    delete i;

    std::cout << std::endl << "─────────────────────────────────" << std::endl;
    std::cout << "Test 2:" << std::endl;
    std::cout << "─────────────────────────────────" << std::endl;

    AAnimal *animals[6];
    for (int i = 0; i < 3; ++i) {
        animals[i] = new Dog();
        animals[i + 3] = new Cat();
    }
    std::cout << "─────────────────────────────────" << std::endl;

    for (int i = 0; i < 6; ++i) {
        animals[i]->makeSound();
    }
    std::cout << "─────────────────────────────────" << std::endl;

    for (int i = 0; i < 6; ++i) {
        delete animals[i];
    }
    return 0;
}