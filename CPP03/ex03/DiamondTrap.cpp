#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name + "_frag"), ScavTrap(name + "_scav"), _name(name) {
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
    std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : FragTrap(other), ScavTrap(other) {
    _name = other._name;
    std::cout << "Copy constructor called for DiamondTrap" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "Copy assignment operator called for DiamondTrap" << std::endl;
    return *this;
}

void DiamondTrap::attack(const std::string &target) {
    if (ScavTrap::_energyPoints > 0 && FragTrap::_hitPoints > 0) {
        std::cout << "DiamondTrap " << _name << " attacks " << target;
        std::cout << ", causing " << FragTrap::_attackDamage << " points of damage!" << std::endl;
        ScavTrap::_energyPoints--;
    } else {
        std::cout << "DiamondTrap " << _name << " cannot attack!" << std::endl;
    }
}

void DiamondTrap::takeDamage(int amount) {
    if (amount >= FragTrap::_hitPoints) {
        FragTrap::_hitPoints = 0;
        std::cout << "DiamondTrap " << _name << " has been destroyed!" << std::endl;
    } else {
        FragTrap::_hitPoints -= amount;
        std::cout << "DiamondTrap " << _name << " takes " << amount;
        std::cout << " points of damage! Remaining hit points: " << FragTrap::_hitPoints << std::endl;
    }
}

void DiamondTrap::beRepaired(int amount) {
    if (ScavTrap::_energyPoints > 0 && FragTrap::_hitPoints > 0) {
        FragTrap::_hitPoints += amount;
        ScavTrap::_energyPoints--;
        std::cout << "DiamondTrap " << _name << " repairs himself for " << amount;
        std::cout << " points! New hit points: " << FragTrap::_hitPoints << std::endl;
    } else {
        std::cout << "DiamondTrap " << _name << " cannot be repaired!" << std::endl;
    }
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << ", my FragTrap name is " << FragTrap::_name;
    std::cout << ", and my ScavTrap name is " << ScavTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "Default DiamondTrap destructor called " << std::endl;
}
