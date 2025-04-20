#include "phonebook.h"

void exit() {
    std::cout << "Exiting program....." << std::endl;
}

void search() {
    std::cout << ".__________________________________________________________." << std::endl;
    std::cout << "| index | first name | last name | nickname | phone number |" << std::endl;
    std::cout << ".__________________________________________________________." << std::endl;
}

void add() {
    char info[999];
    
    std::cout << "First name: ";
    std::cin >> info;
    // setFirstName(info);
    std::cout << "Last name: ";
    std::cin >> info;
    // setLastName(info);
    std::cout << "Nickname: ";
    std::cin >> info;
    // setNickname(info);
    std::cout << "Phone number: ";
    std::cin >> info;
    // setPhoneNumber(info);
    std::cout << "Darkest secret: ";
    std::cin >> info;
    // setDarkestSecret(info);
    std::cout << "Contact added!" << std::endl;
}

int main() {
    char command[7];

    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
    std::cout << "> ";
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
