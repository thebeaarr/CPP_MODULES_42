#pragma once


#include <iostream>
#include <string>




template <typename T>

#include <exception>
class  Array
{
	private : 
		T *_data ;
		unsigned int _size ;
	public :
		Array(): _data(NULL) , _size(0){}
		Array(unsigned int n): _data(T new[n]()) , _size(n){}
		Array(const Array &other)
		{
			this->_size = other._size ;
			this->_data = T new[n]();
			for(int i = 0 ; i < this->_size ; i++)
				this->_data[i] = other._data[i];
		}

		Array &operator=(const Array &other)
		{
			if(&other != this  )
			{
				this->_size = other._size ;
				this->_data = T new[n]();
				for(int i = 0 ; i < this->_size ; i++)
				this->_data[i] = other._data[i];
			}
			
			return *this ;
		}
		T &operator[](unsigned int index)
		{
			if(index >= this->size)
				throw std::out_of_range;
			return _data[index];
		}
		const T &operator[](unsigned int index) const
		{
			if(index >= this->size)
				throw std::out_of_range;
			return _data[index];
		}
		
		const void size() const 
		{
			return this->_size ;
		}

		~Array()
		{
			delete[] _data;
		}
		
};