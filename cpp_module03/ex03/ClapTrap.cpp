#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("default"), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name_c)
	: name(name_c), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), _hit_pts(other._hit_pts),
		_energy_pts(other._energy_pts), _attack_dmg(other._attack_dmg)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		_hit_pts = other._hit_pts;
		_energy_pts = other._energy_pts;
		_attack_dmg = other._attack_dmg;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap " << name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hit_pts > 0 && _energy_pts > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target
			<< ", causing " << _attack_dmg << " points of damage!" << std::endl;
		_energy_pts--;
	}
	else if(_hit_pts == 0)
		std::cout << "ClapTrap " << name << " cannot attack because it has no hit points!" << std::endl;
	else if(_energy_pts == 0)
		std::cout << "ClapTrap " << name << " cannot attack due to insufficient energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hit_pts > 0)
	{
		_hit_pts = (_hit_pts < amount) ? 0 : _hit_pts - amount;
		std::cout << "ClapTrap " << name << " takes " << amount
				<< " points of damage! Remaining HP: " << _hit_pts << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_pts > 0 && _energy_pts > 0)
	{
		std::cout << "ClapTrap " << name << " repairs itself for "
					 << amount << " hit points." << std::endl;
		_hit_pts += amount;
		_energy_pts--;
	}
	else
		std::cout << "ClapTrap " << name << " can’t repair: no hit points or energy left." << std::endl;
}
