#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(std::string const &type) : AMateria(type)
{

}


Ice::Ice(const Ice &obj): AMateria(obj)
{

}

void Ice::use(ICharacter &target)
{
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << "*" << std::endl ;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}


Ice &Ice::operator=(const Ice &obj)
{
	(void)obj;
	return *this ;
}

Ice::~Ice()
{
	
}