#include "iter.hpp"


int main()
{
	int *a = new int[10];
	for(int i = 0 ; i < 10 ; i++)
	{
		a[i] = 10 ;
	}
	
	
	iter(a , 10 , func<int>);
	for(int i = 0 ; i < 10 ; i++)
	{
		std::cout << a[i] << std::endl ;
	}
}