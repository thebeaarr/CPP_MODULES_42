#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hit_pts = 100;
	_energy_pts = 50 ;
	_attack_dmg = 20 ;
	std::cout << "Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_attack_dmg = 20 ;
	this->_hit_pts=  100;
	this->_energy_pts  = 50;
	std::cout << "Default constructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name 
				<< " has entered Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &others )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &others)
		ClapTrap::operator=(others);
	return *this ;
}


