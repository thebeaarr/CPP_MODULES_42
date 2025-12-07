#include "HumanB.hpp"

void HumanB::attack()
{
        std::cout << nameb << " attacks with their " << wb->getType() << std::endl;
}

HumanB::HumanB(std::string n) : nameb(n) , wb(0x0)
{
    std::cout << "constructor" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "destructor HumanB" << std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
    wb = &w;
    std::cout << "constructor HumanB" << std::endl;
}

HumanB::HumanB(std::string n , Weapon &w): nameb(n)
{
    this->setWeapon(w);
}
