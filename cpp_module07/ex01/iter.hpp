#pragma once

#include <iostream>

template <typename T>
void iter(T *a , const int &value ,void (*f)(T &))
{
	for(int i =  0 ; i < value ; i++)
	{
		f(a[i]);
	}
}


template<typename T>
void func(T &a)
{
	a++;
}
