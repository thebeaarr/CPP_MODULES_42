#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    try
    {
    std::string s(av[1]);
    RPN rpn(s);
    rpn.reverse_polish_notation();
    

    }
    catch(std::exception &e )
    {
        std::cout << e.what() << std::endl ;
    }
    
    return 0;
}