#include "Zombie.hpp"

void Zombie::setName(std::string name )
{
    this->name = name ;
}

std::string Zombie::getName()
{
    return name ;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->setName(name);
}
