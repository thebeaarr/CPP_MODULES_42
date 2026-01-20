#include "Array.hpp"

template <typename T>
Array<T>::Array(): _data(NULL) , _size(0){}


template <typename T>
Array<T>::Array(unsigned int n): _data(new T[n]()) , _size(n){}


template <typename T>
Array<T>::Array(const Array &other)
{
	this->_size = other._size ;
	this->_data = new T[this->_size]();
	for(int i = 0 ; i < this->_size ; i++)
		this->_data[i] = other._data[i];
}


template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if(&other != this)
	{
		this->_size = other._size;
		delete[] _data ;
		this->_data = new T[this->_size]();
		for(int i = 0 ; i < this->_size ; i++)
		this->_data[i] = other._data[i];
	}
	
	return *this ;
}

template<typename T>

T &Array<T>::operator[](unsigned int index)
{
	if(index >= this->_size)
		throw std::exception();
	return _data[index];
}


template<typename T>

const T &Array<T>::operator[](unsigned int index) const 
{
	if(index >= this->_size)
		throw std::exception();
	return _data[index];
}


template<typename T>
const unsigned int &Array<T>::size() const 
{
	return this->_size ;
}



template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}