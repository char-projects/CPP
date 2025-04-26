# include "PhoneBook.hpp"
# include <iostream>
# include <cstring>

PhoneBook::PhoneBook() {
	this->_id = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::search() {
    int i = 0;
    std::cout << "+═══════════════════════════════════════════+" << std::endl;
    std::cout << "|     index| firstname| last name|  nickname|" << std::endl;
    std::cout << "+═══════════════════════════════════════════+" << std::endl;
    while (i < this->_id && this->_id < 8 && i < 8) {
        std::cout << "|         " << i << "| ";
        std::cout << this->_contacts[i].getFirstName() << "| ";
        std::cout << this->_contacts[i].getLastName() << "| ";
        std::cout << this->_contacts[i].getNickname() << "| ";
        std::cout << std::endl;
        if (this->_id == this->_id - 1)
            std::cout << "|───────────────────────────────────────────|" << std::endl;
        else
            std::cout << "+───────────────────────────────────────────+" << std::endl;
        i++;
    }
    std::string index;
    if (i == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    else {
        do {
            std::cout << PURPLE "Search for index: " WHITE;
            std::getline(std::cin, index);
            if (index.empty() || index.length() != 1 || (index[0] - '0') >= i || index[0] < '0' || index[0] > '8') {
                std::cout << RED "Invalid index" WHITE << std::endl;
            }
        } while (index.empty() || index.length() != 1 || (index[0] - '0') >= i || index[0] < '0' || index[0] > '8');
        int id = index[0] - '0';
        std::cout << "+───────────────────────────+" << std::endl;
        std::cout << "| Index:                  " << id << " |" << std::endl;
        std::cout << "| First name:     " << this->_contacts[id].getFirstName() << " |" << std::endl;
        std::cout << "| Last name:      " << this->_contacts[id].getLastName() << " |" << std::endl;
        std::cout << "| Nickname:       " << this->_contacts[id].getNickname() << " |" << std::endl;
        std::cout << "| Phone number:   " << this->_contacts[id].getPhoneNumber() << " |" << std::endl;
        std::cout << "| Darkest secret: " << this->_contacts[id].getDarkestSecret() << " |" << std::endl;
        std::cout << "+───────────────────────────+" << std::endl;
        std::cout << GREEN "Contact found!" WHITE << std::endl;
    }
}

std::string PhoneBook::validateInput(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
    } while (input.empty());
    return input;
}

void PhoneBook::add() {
    int temp = this->_id % 8;
    if (this->_id >= 8) {
        std::cout << "Phonebook is full, overwriting the contact at index " << temp << std::endl;
    }
    std::cout << "Id: " << temp << std::endl;
    this->_contacts[temp].setFirstName(this->validateInput("Enter first name: "));
    this->_contacts[temp].setLastName(this->validateInput("Enter last name: "));
    this->_contacts[temp].setNickname(this->validateInput("Enter nickname: "));
    std::string info;
    while (true) {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, info);
        bool isValid = true;
        for (size_t i = 0; i < info.size(); i++) {
            if (info[i] < '0' || info[i] > '9') {
                std::cout << RED "Phone number has to be a number!" WHITE << std::endl;
                isValid = false;
                break;
            }
        }
        if (isValid && !info.empty()) {
            this->_contacts[temp].setPhoneNumber(info);
            break;
        }
    }
    this->_contacts[temp].setDarkestSecret(this->validateInput("Enter darkest secret: "));
    std::cout << GREEN "Contact added!" WHITE << std::endl;
    this->_id++;
}
