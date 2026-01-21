#include "Span.hpp"
#include <iostream>

int main()
{
    try{
    Span s(10);
    std::cout << s.longestSpan() << std::endl;
    std::cout << s.shortestSpan() << std::endl ;

    }catch(std::exception &e)
    {
        std::cout << e.what() ;
    }
}

