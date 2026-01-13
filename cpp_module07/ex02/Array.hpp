#pragma  once 


#include <string>
#include <iostream>

template <typename T>
class Array
{
	private :
		T *a ;
	public :
		Array();
		Array(unsigned int n) 
		{
			a = new T[n];
		}
		
		Array &operator=(const Array &obj)
		{
			if(this != &obj)
			{
				this->a = new T[](obj.a);
			}
			return *this ;
		}
		Array(const Array &obj)
		{
			
		}
};