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
        typedef std::vector<unsigned int>::iterator itvec;
        std::vector<unsigned int> data;
        typedef std::vector<std::pair<int , int > >::iterator itpairs ;
    public: 
        PmergeMe();
        PmergeMe(std::string &cp);
        PmergeMe(const PmergeMe &obj);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &obj);


        void fordjohnson();
        void valid_expr();
        void get_data();
        void printer();

};