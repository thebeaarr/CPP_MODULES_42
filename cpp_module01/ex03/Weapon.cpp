#include "Weapon.hpp"

const std::string &Weapon::getType() const
{
    return type;
}

void Weapon::setType(std::string newt)
{
    this->type = newt;
}

Weapon::Weapon(std::string type)
{
    this->setType(type);
    std::cout << type<< " CREATED!" << std::endl ;
}

Weapon::~Weapon()
{
    std::cout << "destructor weapon" << std::endl;
}
