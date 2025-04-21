# include "PhoneBook.hpp"
# include <iostream>
# include <cstring>

int main() {
    PhoneBook p;
    std::string command;

    while (command != "EXIT") {
        std::cout << RED "Enter a command (ADD | SEARCH | EXIT): " WHITE;
        std::getline(std::cin, command);
        if (command == "ADD") {
            p.add();
        } else if (command == "SEARCH") {
            p.search();
        } else if (command == "EXIT") {
            std::cout << "Exiting program....." << std::endl;
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
}