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
    long value;

    while (ss >> value)
    {
        if (value <= 0)
            throw std::runtime_error("ERROR");

        if (value > INT_MAX)
            throw std::runtime_error("ERROR");

        data.push_back(static_cast<int>(value));
    }

    if (data.empty())
        throw std::runtime_error("ERROR");
}


void PmergeMe::printer()
{
    itvec it = data.begin();
    for(; it != data.end(); ++it)
        std::cout << *it  << " "; 
}




void PmergeMe::fordjohnson()
{
    int n = data.size();
    int Npairs = n / 2 ;
    std::vector<std::pair<int , int> > vecpairs ;

    for(int i = 0 ; i < Npairs ; i++)
    {
        unsigned int a = 
    }
}