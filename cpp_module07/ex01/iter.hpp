#pragma once

#include <iostream>

template <typename T , typename F >
void iter(T *a , const int &value ,F f)
{
	for(int i =  0 ; i < value ; i++)
	{
		f(a[i]);
	}
}
