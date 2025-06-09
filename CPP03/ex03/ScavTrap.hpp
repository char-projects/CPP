#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// ScavTrap inherits everything from ClapTrap
class ScavTrap : public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);

    ScavTrap &operator=(const ScavTrap &other);

    void attack(const std::string &target);
    void takeDamage(int amount);
    void beRepaired(int amount);
    void guardGate();

    ~ScavTrap();
};

#endif