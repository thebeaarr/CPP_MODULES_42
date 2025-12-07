#include "Cure.hpp"


Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(std::string const &type ) : AMateria(type)
{

}

Cure::Cure(const Cure &obj) : AMateria(obj)
{

}


void Cure::use(ICharacter &target)
{
	std::cout << "Cure: * heals " << target.getName() << "'s wounds*" << std::endl ;
}


AMateria *Cure::clone() const
{
	return new Cure(*this);
}

Cure &Cure::operator=(const Cure &obj)
{
	(void)obj;
	return *this ;
}



Cure::~Cure()
{
	
}