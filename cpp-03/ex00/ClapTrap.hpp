#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
  private:
    std::string name;
    int _hits;
    int _energy;
    int _attack_damage;
  public:
    ClapTrap();
    ClapTrap(ClapTrap const &);
    ClapTrap &operator=(ClapTrap const &);
    ~ClapTrap();

    ClapTrap(std::string const &);

};
