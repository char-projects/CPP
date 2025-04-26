#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit) {
    initial_deposit = 0;
    std::cout << "Constructor called" << std::endl;
}

Account::~Account() {
    std::cout << "Destructor called" << std::endl;
}