#include "Zombie.hpp"

int main()
{
  Zombie *hz = new Zombie("heap zombie");
  hz->announce();
  Zombie a("stack");
  a.announce();
  randomChump("stack zombie");
  delete hz;
}