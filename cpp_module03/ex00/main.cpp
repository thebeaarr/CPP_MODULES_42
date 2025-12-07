
#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");
	a.attack("Bravo");
	b.takeDamage(5);
	b.attack("Alpha");
	a.takeDamage(3);
	a.beRepaired(4);
	b.beRepaired(2);
	ClapTrap c(a);
	c.attack("Bravo");
	ClapTrap d;
	d = b;
	d.attack("Alpha");
	return 0;
}
