#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string const &type );
		Ice(const Ice &);
		void use(ICharacter &target);
		Ice &operator=(const Ice &obj);
		AMateria* clone() const;
		~Ice();
};