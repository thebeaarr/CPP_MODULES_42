#pragma once
#include "AMateria.hpp"
class GargbageColl
{
	public:
		AMateria **m ;
		int size;
	public :
		GargbageColl();
		void add(AMateria* m);
		GargbageColl &operator=(const GargbageColl &);
		GargbageColl(const GargbageColl &);
		~GargbageColl();
};
