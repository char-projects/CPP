# include "PhoneBook.hpp"
# include <iostream>
# include <cstring>

PhoneBook::PhoneBook() {
	this->_id = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::search() {
    std::cout << ".══════════════════════════════════════════════════════════." << std::endl;
    std::cout << "| index | first name | last name | nickname | phone number |" << std::endl;
    std::cout << ".══════════════════════════════════════════════════════════." << std::endl;
}

void PhoneBook::add() {
    std::string info = " ";
    
    std::cout << "Id: " << this->_id << std::endl;
    if (this->_id < 8) {
        std::cout << "First name: ";
        std::cin >> info;
        // this->_contacts[_id].setFirstName(info);
        std::cout << "Last name: ";
        std::cin >> info;
        // this->_contacts[_id].setLastName(info);
        std::cout << "Nickname: ";
        std::cin >> info;
        // this->_contacts[_id].setNickname(info);
        std::cout << "Phone number: ";
        std::cin >> info;
        // this->_contacts[_id].setPhoneNumber(info);
        std::cout << "Darkest secret: ";
        std::cin >> info;
        // this->_contacts[_id].setDarkestSecret(info);
        std::cout << "Contact added!" << std::endl;
        this->_id++;
    } else {
        std::cout << "Phonebook is full, cannot add more contacts." << std::endl;
    }
}
