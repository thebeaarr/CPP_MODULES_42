#include "MateriaSource.hpp"

//Constructor
MateriaSource::MateriaSource() : materiaCount(0)
{
	for (int i = 0; i < maxMaterias; ++i)
		materias[i] = NULL;
}

//Copy Constructor
MateriaSource::MateriaSource(const MateriaSource &other) : materiaCount(0)
{
	for (int i = 0; i < maxMaterias; ++i)
		materias[i] = other.materias[i]->clone();
	*this = other;
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < maxMaterias; ++i)
		{
			delete materias[i];
			materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
		}
		materiaCount = other.materiaCount;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < maxMaterias; ++i)
		delete materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (materiaCount < maxMaterias && m)
	{
		if (!materias[materiaCount]) {
			materias[materiaCount] = m;
			materiaCount++;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < materiaCount; ++i)
	{
		if (materias[i]->getType() == type)
		{
			// if(materias[i] == NULL)
				return materias[i]->clone();
		}
	}
	return NULL;
}
