# include "PhoneBook.hpp"
# include <iostream>
# include <cstring>

int main() {
    PhoneBook p;
    std::string command;

    while (!std::cin.fail() && command != "EXIT") {
        std::cout << PURPLE "Enter a command (ADD | SEARCH | EXIT): " WHITE;
        std::getline(std::cin, command);
        if (command == "ADD") {
            p.add();
        } else if (command == "SEARCH") {
            p.search();
        } else if (std::cin.fail() || command == "EXIT") {
            std::cout << "Exiting program....." << std::endl;
        } else {
            std::cout << RED "Invalid command" WHITE << std::endl;
        }
    }
}