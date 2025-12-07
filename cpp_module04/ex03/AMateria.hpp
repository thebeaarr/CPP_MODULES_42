#pragma once 

#include <string>
#include <iostream>
#include "ICharacter.hpp"
class ICharacter; 

class AMateria
{
protected:
std::string type; 
public:
AMateria(std::string const & type);
AMateria();
AMateria &operator=(const AMateria &);
AMateria(const AMateria &);
std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
virtual ~AMateria();
};
