# include "PhoneBook.hpp"
# include <iostream>
# include <cstring>

PhoneBook::PhoneBook() {
	this->_id = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::search() {
    std::cout << ".════════════════════════════════════════════════════." << std::endl;
    std::cout << "| id | firstname | last name |  nickname | phone nbr |" << std::endl;
    std::cout << ".════════════════════════════════════════════════════." << std::endl;
    for (int i = 0; i < this->_id; i++) {
        std::cout << "| " << i << " | ";
        std::cout << this->_contacts[i].getFirstName() << " | ";
        std::cout << this->_contacts[i].getLastName() << " | ";
        std::cout << this->_contacts[i].getNickname() << " | ";
        std::cout << this->_contacts[i].getPhoneNumber() << " |" << std::endl;
        std::cout << ".────────────────────────────────────────────────────." << std::endl;
    }
}

void PhoneBook::add() {
    std::string info = " ";
    
    std::cout << "Id: " << this->_id << std::endl;
    if (this->_id >= 8) {
        this->_id = 0;
    }
    else {
        std::cout << "First name: ";
        std::getline(std::cin, info);
        this->_contacts[_id].setFirstName(info);
        std::cout << "Last name: ";
        std::getline(std::cin, info);
        this->_contacts[_id].setLastName(info);
        std::cout << "Nickname: ";
        std::getline(std::cin, info);
        this->_contacts[_id].setNickname(info);
        std::cout << "Phone number: ";
        std::getline(std::cin, info);
        this->_contacts[_id].setPhoneNumber(info);
        std::cout << "Darkest secret: ";
        std::getline(std::cin, info);
        this->_contacts[_id].setDarkestSecret(info);
        std::cout << "Contact added!" << std::endl;
        this->_id++;
    }
}
