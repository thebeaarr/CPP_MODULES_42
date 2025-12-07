#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria()
{

}

AMateria::AMateria(const AMateria &ths)
{
	this->type = ths.type ;
}

std::string const &AMateria::getType() const 
{
	return this->type;
}


void AMateria::use(ICharacter & target)
{
	std::cout << "AMateria: " << target.getName() << " with type " << this->type << "." << std::endl;
}

AMateria::~AMateria()
{
	
}