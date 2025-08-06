#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << namea << " attacks with their " << wa.getType() << std::endl;
}


HumanA::HumanA(std::string name , Weapon &w) : namea(name) , wa(w)
{
    std::cout << "constructor HumanA" << std::endl ;
}


void HumanA::setWeapon(Weapon &w)
{
    this->wa.setType(w.getType());
}

HumanA::~HumanA()
{
    std::cout << "Destructor HumanA" << std::endl ;
}
