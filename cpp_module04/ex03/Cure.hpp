#pragma once
#include "AMateria.hpp"
class Cure: public AMateria
{
	public :
	Cure();
	Cure(std::string const &type);
	Cure(const Cure &);
	void use(ICharacter &target);
	Cure &operator=(const Cure &);
	AMateria *clone() const;
	~Cure();
};