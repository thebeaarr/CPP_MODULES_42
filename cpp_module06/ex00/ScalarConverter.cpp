#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <algorithm>


ScalarConverter::ScalarConverter()
{

}


ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    (void)obj;
}


ScalarConverter::~ScalarConverter()
{

}



ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return *this ;
}

void ScalarConverter::convert(std::string &str)
{
    if (!isdigit(str[0]))
    {
        if (str.length() == 1)
        {
            char c = str[0];
            std::cout << "char   : " << c << std::endl ;
            std::cout << "int    : " << static_cast<int>(c) << std::endl ;
            std::cout << "float  : " << static_cast<float>(c) << "f" << std::endl ;
            std::cout << "double : " << static_cast<double>(c) << std::endl;
            return ;
        }
    }
    char *end;
    double a = strtod(str.c_str(),&end );
    if(str == "+inf" || str == "-inf" || str == "nan" || str == "+inff" || str == "-inff" || str == "nanf")
    {
        std::cout << "char   : impossible" <<  std::endl ;
        std::cout << "int    : impossible" << std::endl ;
        std::cout << "float  : " << str << "f" << std::endl ;
        std::cout << "double : " << str << std::endl;
        return ;
    }
    if(*end != '\0')
    {
        std::cout << "Invalid input" << std::endl ;
        return ;
    }

    std::cout << a<< std::endl ;
    if(a < 32 || a > 127  || a <= -128)
        std::cout << "char   : " << "Non displayable" << std::endl ;
    else
        std::cout << "char   : " << static_cast<char>(a)<<  std::endl ;
    std::cout << "int    : " << static_cast<int>(a)<<  std::endl ;
    std::cout << "float  : "  << static_cast<float>(a)<<  "f" << std::endl ;
    std::cout << "double : " << static_cast<double>(a) << std::endl ;
}