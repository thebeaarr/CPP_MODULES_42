#pragma once


#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>


class PmergeMe
{
    private:
        std::string expr ;
        typedef std::string::iterator itstr;
        std::vector<unsigned int> data;
    public: 
        PmergeMe();
        PmergeMe(std::string &cp);
        PmergeMe(const PmergeMe &obj);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &obj);
        void valid_expr();
        void get_data();
        void printer();
};