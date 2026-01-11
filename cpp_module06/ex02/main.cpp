#include "Base.hpp"



int main()
{
    for(int i = 0 ; i < 4  ; i++)
    {
        std::cout << "---------- TEST " << i << "-----------" << std::endl ;
        Base *b   = generate();
        identify(b);
        identify(*b);
    }
}