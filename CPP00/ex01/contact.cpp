# include "PhoneBook.hpp"
# include <iostream>
# include <cstring>

std::string Contact::getFirstName() const {
    return _firstName;
}
void Contact::setFirstName (std::string input){
    if (input.length() < 10)
        _firstName = input;
    else
        _firstName = input.substr(0, 8) + '.';
    std::cout << "First name set to: " << _firstName << std::endl;      
};

std::string Contact::getLastName() const {
    return _lastName;
}

void Contact::setLastName (std::string input){
    if (input.length() < 10)
        _lastName = input;
    else
        _lastName = input.substr(0, 8) + '.';
    std::cout << "Last name set to: " << _lastName << std::endl;
};

std::string Contact::getNickname() const {
    return _nickname;
}

void Contact::setNickname (std::string input) {
    if (input.length() < 10)
        _nickname = input;
    else
        _nickname = input.substr(0, 8) + '.';
    std::cout << "Nickname set to: " << _nickname << std::endl;
};

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

void Contact::setPhoneNumber (std::string input){
    if (input.length() < 10)
        _phoneNumber = input;
    else
        _phoneNumber = input.substr(0, 8) + '.';
    std::cout << "Phone number set to: " << _phoneNumber << std::endl;
};

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

void Contact::setDarkestSecret (std::string input){
    if (input.length() < 10)
        _darkestSecret = input;
    else
        _darkestSecret = input.substr(0, 8) + '.';
    std::cout << "Darkest secret set to: " << _darkestSecret << std::endl;
};
