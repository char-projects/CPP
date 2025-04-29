#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit) {
    initial_deposit = 0;
    std::cout << "Constructor called" << std::endl;
}

Account::~Account() {
    std::cout << "Destructor called" << std::endl;
}

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    std::cout << "Display accounts infos called" << std::endl;
}

void Account::displayStatus(void) const {
    std::cout << "Display status called" << std::endl;
}

void Account::makeDeposit(int deposit) {
    std::cout << "Make deposit called" << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    std::cout << "Make withdrawal called" << std::endl;
}

int Account::checkAmount(void) const {
    std::cout << "Check amount called" << std::endl;
}

void Account::_displayTimestamp(void) {
    std::cout << "Display timestamp called" << std::endl;
}