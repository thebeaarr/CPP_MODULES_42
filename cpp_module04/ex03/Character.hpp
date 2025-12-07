#pragma once
#include "ICharacter.hpp"
#include "GagrbageColl.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria* inv[4] ;
		GargbageColl *coll;
	public :
		Character();
		Character(std::string const &name );
		Character(const Character &obj);
		std::string const &getName() const ;
		Character &operator=(const Character &obj);
		~Character();
		void equip(AMateria *m);
		void unequip(int idx ) ;
		void use(int idx , ICharacter &target);
};
