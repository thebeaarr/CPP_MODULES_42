#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called!" << std::endl;
	_hit_pts = FragTrap::_hit_pts;
	_energy_pts = ScavTrap::_energy_pts;
	_attack_dmg = FragTrap::_attack_dmg;
}

void DiamondTrap::attack(const std::string &target) 
{
	std::cout << "DiamondTrap " << name << " is attacking " << target << " using ScavTrap's attack!" << std::endl;
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(const std::string &param_name): ClapTrap(param_name + "_clap_name"), ScavTrap(param_name), FragTrap(param_name)
{
	std::cout << "DiamondTrap parameterized constructor called for " << param_name << "!" << std::endl;
	this->name = param_name ;
	_hit_pts = FragTrap::_hit_pts;
	_energy_pts = ScavTrap::_energy_pts;
	_attack_dmg = FragTrap::_attack_dmg;
}

	void DiamondTrap::whoAmI()
	{
		std::cout << "I am DiamondTrap " << this->name << "!" << std::endl;
		std::cout << "My ClapTrap name is " << ClapTrap::name<< "." << std::endl;
	}


	DiamondTrap::~DiamondTrap()
	{
		std::cout << "DiamondTrap Destructor called " << this->name << "." << std::endl;
	}

	DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
	{
		std::cout << "DiamondTrap copy assignment operator called for " << other.name << "!" << std::endl;
		this->name = other.name;
		this->_attack_dmg = other._attack_dmg;
		this->_energy_pts = other._energy_pts;
		this->_hit_pts = other._hit_pts;
		return *this;
	}
