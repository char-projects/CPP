#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"

int main()
{
    std::cout << "───────────────────────────────────────────" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "───────────────────────────────────────────" << std::endl;
    std::cout << "Animal type: " << meta->getType() << " " << std::endl << "Sound: ";
    i->makeSound(); // will output the cat sound!

    std::cout << "───────────────────────────────────────────" << std::endl;
    std::cout << "Animal type: " << j->getType() << " " << std::endl << "Sound: ";
    j->makeSound();

    std::cout << "───────────────────────────────────────────" << std::endl;
    std::cout << "Animal type: " << i->getType() << " " << std::endl << "Sound: ";
    meta->makeSound();

    // ...

    return 0;
}