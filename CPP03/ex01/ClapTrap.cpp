#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default ClapTrap constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "Copy constructor called for ClapTrap" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "Copy assignment operator called for ClapTrap" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target;
        std::cout << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "ClapTrap " << _name << " cannot attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(int amount) {
    if (amount >= _hitPoints) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount;
        std::cout << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs himself for " << amount;
        std::cout << " points! New hit points: " << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " cannot be repaired!" << std::endl;
    }
}

ClapTrap::~ClapTrap() {
    std::cout << "Default ClapTrap destructor called" << std::endl;
}
