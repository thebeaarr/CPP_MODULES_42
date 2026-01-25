#pragma once
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <climits>

class PmergeMe
{
    private:
        std::string expr ;
        typedef std::string::iterator itstr;
        typedef std::vector<std::pair<unsigned int , unsigned int > >::const_iterator itpair;
        typedef std::vector<unsigned int>::iterator itvec;
        std::vector<unsigned int> data;
        typedef std::vector<std::pair<unsigned int , unsigned int > >::iterator itpairs ;
        void compare_pairs(const std::vector<unsigned int>& input, std::vector<std::pair<unsigned int, unsigned int> >& pairs,bool& has_straggler,unsigned int& straggler);
            void small(std::vector<unsigned int> & P , std::vector<std::pair<unsigned int , unsigned int > >  const & pairs);
        void large(std::vector<unsigned int> &S , std::vector<std::pair<unsigned int , unsigned int> > const &  pairs);
    public: 
        PmergeMe();
        PmergeMe(std::string &cp);
        PmergeMe(const PmergeMe &obj);
        ~PmergeMe();
        
        PmergeMe &operator=(const PmergeMe &obj);
        void algo();
        void fordjohnson(std::vector<unsigned int> &data);
        void valid_expr();
        void get_data();
        void printer();

};