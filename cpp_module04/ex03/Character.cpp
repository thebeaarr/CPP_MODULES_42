#include "Character.hpp"

Character::Character() : name("default"), coll(new GargbageColl())
{
	for(int i =0 ; i< 4; i++)
		this->inv[i] = NULL;
}

std::string const &Character::getName() const
{
	return this->name;
}

Character::Character(std::string const &name ) : name(name) , coll(new GargbageColl())
{
	for(int i = 0;i < 4 ; i++)
		this->inv[i]   = NULL ;
}

Character::Character(const Character &obj) : coll(new GargbageColl())
{
	this->name = obj.getName();
	for(int i = 0 ; i < 4; i++)
		this->inv[i] = NULL;
	for(int i = 0; i < 4; i++)
	{
		if(obj.inv[i])
		{
			this->inv[i] = obj.inv[i]->clone();
		}
	}
}

Character &Character::operator=(const Character &obj)
{
	if(this != &obj)
	{
		this->name = obj.getName();
		for(int i = 0 ; i < 4 ; i++)
		{
			delete this->inv[i] ;
		}
		for(int i  = 0 ; i < 4 ; i ++)
			this->inv[i] = NULL ;
		for(int i = 0 ; i < 4 ; i++)
		{
			this->inv[i] = obj.inv[i]->clone();
		}
	}
	return *this ;
}

void Character::equip(AMateria *m)
{
	if(!m)
		return ;
	for(int index = 0 ; index < 4; index++)
	{
		if(inv[index] == NULL )
		{
			inv[index] = m->clone();
			return ;
		}
	}
	
}
void Character::unequip(int idx)
{
	if((idx >= 0 && idx < 4) && this->inv[idx] != NULL)
	{
		coll->add(inv[idx]);
		inv[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if(idx >= 0 && idx < 4 && inv[idx] != NULL)
		this->inv[idx]->use(target);
}

Character::~Character()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		delete inv[i];
	}
	delete coll ;
}
