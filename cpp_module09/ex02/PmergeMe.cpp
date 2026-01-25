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
void PmergeMe::compare_pairs(std::vector<std::pair<unsigned int, unsigned int> >& pairs, bool& has_straggler,unsigned int& straggler)
{
    size_t i = 0;
    for (; i + 1 < data.size(); i += 2)
    {
        if (data[i] > data[i + 1])
            pairs.push_back(std::make_pair(data[i], data[i + 1]));
        else
            pairs.push_back(std::make_pair(data[i + 1], data[i]));
    }

    has_straggler = (data.size() % 2);
    if (has_straggler)
        straggler = data.back();
}


void PmergeMe::large(std::vector<unsigned int> & S , std::vector<std::pair<unsigned int , unsigned int > >  const & pairs)
{

    itpair it = pairs.begin() ;
    for( ; it != pairs.end() ; ++it)
        S.push_back(it->first);
}



void binary_insert(std::vector<unsigned int>& chain, unsigned int value)
{
    std::vector<unsigned int>::iterator pos =
        std::lower_bound(chain.begin(), chain.end(), value);
    chain.insert(pos, value);
}


void PmergeMe::fordjohnson(std::vector<unsigned int> &data)
{
    std::cout <<"size : " <<  data.size() << std::endl ;
    if(data.size() <= 2)
        return ;
    bool has_straggler ;
    unsigned int straggler ;
    std::vector< std::pair<unsigned int ,unsigned  int> >   pairs ;
    compare_pairs(pairs, has_straggler ,  straggler) ;
    std::vector<unsigned int> S  ;
    large(S  , pairs);
    fordjohnson(S);
    std::vector<unsigned int> main_chain ;
    main_chain.push_back(pairs[0].second);
    for(int i  = 0 ; i < S.size(); i++)
        main_chain.push_back(S[i]);        
    for(int i = 0 ; i < pairs.size() ; i++)
        binary_insert(main_chain ,pairs[i].second);
    binary_insert(main_chain , straggler);
    
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