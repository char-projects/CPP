#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
  // Classes who inherit from ClapTrap will have access to these members
  protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

  public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);

    ClapTrap &operator=(const ClapTrap &other);

    void attack(const std::string &target);
    void takeDamage(int amount);
    void beRepaired(int amount);

    ~ClapTrap();
};

#endif