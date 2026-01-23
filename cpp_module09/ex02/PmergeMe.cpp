#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(std::string &cp) : expr(cp) {}


PmergeMe::PmergeMe(const PmergeMe  &obj):expr(obj.expr){}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if(this != &obj)
        this->expr = obj.expr;
    return *this ;    
}


PmergeMe::~PmergeMe(){}





void PmergeMe::valid_expr()
{
    itstr it = expr.begin();
    for(; it != expr.end(); it++)
    {
        if(!std::isdigit(*it) && !std::isspace(*it))
            throw std::runtime_error("ERROR");
    }
}




void PmergeMe::get_data()
{
    std::stringstream ss(expr);
    long number; 
    while(ss >> number)
    {
        data.push_back(number);
        std::cout << number << std::endl ;
    }
}
