#pragma once 
#include <deque>
#include <stack>



template <typename T,typename container = std::deque<T> >
class MutantStack: public std::stack<T, container> 
{
    public:
        typedef typename container::iterator iterator;
        typedef typename container::const_iterator const_iterator;
        typedef typename container::reverse_iterator reverse_iterator;
        typedef typename container::const_reverse_iterator const_reverse_iterator;

        iterator begin(){return this->c.begin();}
        iterator end(){return this->c.end();}

        const_iterator begin()const {return this->c.begin();}
        const_iterator end() const {this->c.end();}

        reverse_iterator rbegin(){return this->c.rbegin();}
        reverse_iterator rend(){return this->c.rend();}

        const_reverse_iterator rbegin() const {return this->c.rbegin();}
        const_reverse_iterator rend() const {return this->c.rend();}
};
