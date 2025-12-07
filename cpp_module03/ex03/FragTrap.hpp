#pragma once
#include "ClapTrap.hpp"
class FragTrap :virtual public ClapTrap
{
	public:
	void highFivesGuys(void);
	FragTrap(const std::string &name );
	FragTrap();
	FragTrap &operator=(const FragTrap &other);
	FragTrap(const FragTrap &other);
	~FragTrap();
};
