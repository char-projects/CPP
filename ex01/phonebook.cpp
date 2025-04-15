#include "Contact.hpp"
#include "PhoneBook.hpp"
# include <iostream>
# include <cstring>

void exit() {
    std::cout << "Exiting program....." << std::endl;
}

void search() {
    std::cout << "Searching contact....." << std::endl;
}

void add() {
    std::cout << "Adding contact....." << std::endl;
}

int main() {
    char command[7];

    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
    std::cin >> command;
    if (strcmp(command, "ADD") == 0) {
        add();
    } else if (strcmp(command, "SEARCH") == 0) {
        search();
    } else if (strcmp(command, "EXIT") == 0) {
        exit();
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}
