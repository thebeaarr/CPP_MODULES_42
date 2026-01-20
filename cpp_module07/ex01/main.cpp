#include "iter.hpp"



template<typename T>
void iter(T &a)
{
	a++;
}
int main()
{
	int T[]  = { 1, 2, 3, 4, 0};
	for(int i = 0 ; i < 5 ; i++)
		std::cout << T[i] << std::endl ;
	
}