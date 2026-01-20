#include "iter.hpp"

template<typename T>
void func(T &a)
{
	a++;
}

int main()
{
	int a[10] = { 10 , 10 , 20 , 10 , 10 , 10 , 10 , 10 , 10 ,10};
	
	
	iter(a , 10 , func<int >);
	for(int i = 0 ; i < 10 ; i++)
	{
		std::cout << a[i] << std::endl ;
	}
}