#include "GagrbageColl.hpp"
GargbageColl::GargbageColl(): size(0)
{
	m = new AMateria*[50];
	for (int i = 0; i < 50; i++)
		m[i] = NULL;
}
GargbageColl::~GargbageColl()
{
	for (int i = 0; i < size; i++)
		delete m[i];
	delete [] m;
}
void GargbageColl::add(AMateria* materia)
{
	if (size < 50)
	{
		m[size] = materia;
		size++;
	}
	else
	{
		AMateria **new_m = new AMateria*[size + 10];
		for (int i = 0; i < size; i++)
			new_m[i] = m[i];
		delete [] m;
		m = new_m;
		m[size] = materia;
		size++;
	}
}

GargbageColl &GargbageColl::operator=(const GargbageColl &other)
{
	if (this != &other)
		(void)other;
	return *this;
}
GargbageColl::GargbageColl(const GargbageColl &other)
{
	size = other.size;
	m = new AMateria*[size];
	for (int i = 0; i < size; i++)
		m[i] = other.m[i]->clone();
}
