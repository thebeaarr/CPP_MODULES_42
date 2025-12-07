#pragma once 
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string &name);
		void guardGate();
		ScavTrap();
		ScavTrap &operator=(const ScavTrap &others);
		ScavTrap(const ScavTrap& others);
		~ScavTrap();
};
