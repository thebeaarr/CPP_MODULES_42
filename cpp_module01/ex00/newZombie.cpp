#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *nz = new Zombie(name);
    return nz;
}

