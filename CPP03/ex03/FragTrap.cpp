#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "Copy constructor called for FragTrap" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "Copy assignment operator called for FragTrap" << std::endl;
    return *this;
}

void FragTrap::attack(const std::string &target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "FragTrap " << this->_name << " attacks " << target;
        std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << "FragTrap " << this->_name << " cannot attack!" << std::endl;
    }
}

void FragTrap::takeDamage(int amount) {
    if (amount >= this->_hitPoints) {
        this->_hitPoints = 0;
        std::cout << "FragTrap " << this->_name << " has been destroyed!" << std::endl;
    } else {
        this->_hitPoints -= amount;
        std::cout << "FragTrap " << this->_name << " takes " << amount;
        std::cout << " points of damage! Remaining hit points: " << this->_hitPoints << std::endl;
    }
}

void FragTrap::beRepaired(int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        this->_hitPoints += amount;
        this->_energyPoints--;
        std::cout << "FragTrap " << this->_name << " repairs herself for " << amount;
        std::cout << " points! New hit points: " << this->_hitPoints << std::endl;
    } else {
        std::cout << "FragTrap " << this->_name << " cannot repair himself!" << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "Default FragTrap destructor called" << std::endl;
}
