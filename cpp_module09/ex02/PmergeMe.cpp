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
void PmergeMe::compare_pairs(
    const std::vector<unsigned int>& input,
    std::vector<std::pair<unsigned int, unsigned int> >& pairs,
    bool& has_straggler,
    unsigned int& straggler)
{
    size_t i = 0;
    for (; i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
        else
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
    }

    has_straggler = (input.size() % 2 != 0);
    if (has_straggler)
        straggler = input.back();
}



void PmergeMe::large(
    std::vector<unsigned int>& S,
    const std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
    for (size_t i = 0; i < pairs.size(); ++i)
        S.push_back(pairs[i].first);
}


void binary_insert(std::vector<unsigned int>& chain, unsigned int value)
{
    std::vector<unsigned int>::iterator pos =
        std::lower_bound(chain.begin(), chain.end(), value);
    chain.insert(pos, value);
}



void PmergeMe::fordjohnson(std::vector<unsigned int>& data)
{
    if (data.size() <= 1)
        return;

    bool has_straggler = false;
    unsigned int straggler = 0;

    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    compare_pairs(data, pairs, has_straggler, straggler);
    
    std::vector<unsigned int> S;
    large(S, pairs);
    fordjohnson(S);
    
    std::vector<unsigned int> main_chain;
    
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first == S[0])
        {
            main_chain.push_back(pairs[i].second);
            break;
        }
    }

    for (size_t i = 0; i < S.size(); ++i)
        main_chain.push_back(S[i]);

    for (size_t i = 1; i < S.size(); ++i) {
    std::vector<unsigned int> pend;
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == S[i]) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    for (size_t i = 0; i < pend.size(); ++i)
        binary_insert(main_chain, pend[i]);
    
    if (has_straggler)
        binary_insert(main_chain, straggler);
            
    data = main_chain;
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

void PmergeMe::algo()
{
    fordjohnson(data);
}


void PmergeMe::printer()
{
    itvec it = data.begin();
    for(; it != data.end(); ++it)
        std::cout << *it  << " "; 
}