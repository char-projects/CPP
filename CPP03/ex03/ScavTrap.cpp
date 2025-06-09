#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "Copy constructor called for ScavTrap" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "Copy assignment operator called for ScavTrap" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ScavTrap " << this->_name << " attacks " << target;
        std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << "ScavTrap " << this->_name << " cannot attack!" << std::endl;
    }
}

void ScavTrap::takeDamage(int amount) {
    if (amount >= this->_hitPoints) {
        this->_hitPoints = 0;
        std::cout << "ScavTrap " << this->_name << " has been destroyed!" << std::endl;
    } else {
        this->_hitPoints -= amount;
        std::cout << "ScavTrap " << this->_name << " takes " << amount;
        std::cout << " points of damage! Remaining hit points: " << this->_hitPoints << std::endl;
    }
}

void ScavTrap::beRepaired(int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        this->_hitPoints += amount;
        this->_energyPoints--;
        std::cout << "ScavTrap " << this->_name << " repairs himself for " << amount;
        std::cout << " points! New hit points: " << this->_hitPoints << std::endl;
    } else {
        std::cout << "ScavTrap " << this->_name << " cannot repair himself!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "Default ScavTrap destructor called" << std::endl;
}

