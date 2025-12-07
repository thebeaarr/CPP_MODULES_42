#pragma once 
#include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(const std::string &name);
		void guardGate();
		ScavTrap();
		ScavTrap &operator=(const ScavTrap &others);
		ScavTrap(const ScavTrap& others);
		~ScavTrap();
};
