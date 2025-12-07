#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	// --- Test ClapTrap ---
	ClapTrap clap("Clappy");
	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);	

	std::cout << "----------------------" << std::endl;

	// --- Test FragTrap ---
	FragTrap frag1("Fraggy1");
	frag1.attack("Boss1");
	frag1.takeDamage(15);
	frag1.beRepaired(5);
	frag1.highFivesGuys();

	std::cout << "----------------------" << std::endl;

	// --- Test FragTrap Copy Constructor ---
	FragTrap frag2(frag1);
	frag2.attack("Boss2");
	frag2.highFivesGuys();

	// --- Test FragTrap Assignment Operator ---
	FragTrap frag3;
	frag3 = frag1;
	frag3.attack("Boss3");
	frag3.highFivesGuys();

	std::cout << "----------------------" << std::endl;

	return 0;
}
