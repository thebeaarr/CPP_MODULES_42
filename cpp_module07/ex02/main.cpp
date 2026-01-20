#include "Array.hpp"



int main()
{
	Array<std::string> array(10) ;
	for(unsigned int i = 0 ; i < array.size() ; i++)
	{
		array[i]  = "mohamed";
	}
	for(unsigned  int i = 0 ; i  < array.size() ; i++)
	{
		std::cout << array[i] << std::endl ;
 	}
}