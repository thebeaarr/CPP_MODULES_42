#pragma once


#include <iostream>
#include <string>


class ClapTrap
{
	private:
		std::string name;
		unsigned int _hit_pts;
		unsigned int _energy_pts;
		unsigned int _attack_dmg ;
	public:
		ClapTrap(std::string name_c);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount );
		void beRepaired(unsigned int amount);
		
		ClapTrap();
		ClapTrap &operator=(const ClapTrap &others);
		ClapTrap(const ClapTrap &);
		~ClapTrap();
};
