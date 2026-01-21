#pragma once



#include <vector>
#include <deque>
#include <list>

#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        unsigned int _N ;
        std::vector<int> _vec ;
    public :
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        int  &operator[](unsigned int index) ;
        const int  &operator[](unsigned int  index)  const  ;
        void addNumber(int number);
        int shortestSpan() ;
        int longestSpan() ;
        template<typename T> void  addNumberranger(T &beg , T &end )
        {
            for(;beg != end ; beg++)
                _vec.push_back(*beg);
        }
};