#pragma once 

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
	private:
		std::string name ;
	public:
		DiamondTrap();
		DiamondTrap(const std::string &string );
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &);
		DiamondTrap(const DiamondTrap &);
		void attack(const std::string &target);
		void whoAmI();
		
};
