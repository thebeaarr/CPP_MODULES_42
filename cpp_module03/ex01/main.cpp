#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// Test ClapTrap
	ClapTrap clap("Clappy");
	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "----------------------" << std::endl;

	// Test ScavTrap default constructor
	ScavTrap scav1;
	scav1.attack("Enemy1");
	scav1.takeDamage(20);
	scav1.beRepaired(10);
	scav1.guardGate(); // Special ability

	std::cout << "----------------------" << std::endl;

	// Test ScavTrap parameterized constructor
	ScavTrap scav2("Scavy");
	scav2.attack("Enemy2");
	scav2.takeDamage(15);
	scav2.beRepaired(5);
	scav2.guardGate();

	std::cout << "----------------------" << std::endl;

	// Test copy constructor
	ScavTrap scav3(scav2);
	scav3.attack("Enemy3");
	scav3.guardGate();

	std::cout << "----------------------" << std::endl;

	// Test assignment operator
	ScavTrap scav4;
	scav4 = scav1;
	scav4.attack("Enemy4");
	scav4.guardGate();

	return 0;
}
