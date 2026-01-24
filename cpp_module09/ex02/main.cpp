#include "PmergeMe.hpp"


int main(int ac, char **av)
{

    try
    {
    if(ac == 1)
        throw std::runtime_error("USAGE : ./PmergeMe [sequence of positive numbers.]");
    
        std::string input;
        for (int i = 1; i < ac; ++i)
        {
            if (i > 1)
                input += ' ';
            input += av[i];
        }

        PmergeMe a(input);
        a.valid_expr();a.get_data();
        a.printer();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
