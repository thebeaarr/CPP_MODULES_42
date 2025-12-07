#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static const int maxMaterias = 4;
		AMateria* materias[maxMaterias];
		int materiaCount;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource& operator=(const MateriaSource &other);
		virtual ~MateriaSource();
		
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(const std::string &type);
};