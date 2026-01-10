#include "ScalarConverter.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert <value>" << std::endl ;
        return 1;
    }
    std::string a(av[1]);
    ScalarConverter::convert(a);
}