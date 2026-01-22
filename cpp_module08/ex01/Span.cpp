#include "Span.hpp"
#include <vector>
#include <exception>
Span::Span() : _N(0)
{

}




Span::Span(unsigned int N ): _N(N)
{

}

Span::Span(const Span &other)
{
    _N = other._N;
    _vec = other._vec ;
}



Span::~Span(){}



Span &Span::operator=(const Span &other)
{
    if(this != &other)
    {
        this->_N  = other._N;
        this->_vec = other._vec;
    }
    return *this ;
}
const int  &Span::operator[](unsigned int index) const 
{
    if(index >= _N)
        throw std::out_of_range("out of range ");
    return _vec[index];
}
int  &Span::operator[](unsigned int index) 
{
    if(index >= _N)
        throw std::out_of_range("out of range ");
    return _vec[index];
}


int Span::longestSpan()
{
    if(_vec.begin() == _vec.end())
        throw std::exception();

    int L = *std::max_element(_vec.begin() , _vec.end()) - *std::min_element(_vec.begin() , _vec.end()) ;
    return L ;
}

int Span::shortestSpan() 
{
    std::vector<int> cpyvec(_vec);
    if(cpyvec.begin() == cpyvec.end())
        throw std::exception();

    std::sort(cpyvec.begin() , cpyvec.end());
    std::vector<int>::iterator it1 ;
    
    int saveprev = *cpyvec.begin() + 1 ;
    int shortest  = *(cpyvec.begin() + 1)  - *cpyvec.begin(); 
    for(it1 = cpyvec.begin() + 2   ; it1 != cpyvec.end() ; it1++)
    {
        if(shortest <= (*it1 - saveprev))
            shortest = *it1 - saveprev; 
        saveprev = *it1 ;
    }
    return shortest ; 
}

void Span::addNumber(int number )
{
    this->_vec.push_back(number);
}