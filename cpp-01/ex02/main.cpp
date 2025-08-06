#include <iostream>
#include <string>


int main()
{
    std::string var("HI THIS IS BRAIN");
    std::string *stringPTR = &var;
    std::string &stringREF = var;
    // the address
    std::cout << " address of the variable : " << &var << std::endl ;
    std::cout  << " address of the pointer : " << stringPTR << std::endl ;
    std::cout << " address of the ref : " << &stringREF << std::endl;
    // the values
    std::cout << "value of the variable : " << var << std::endl;
    std::cout << "value of the pointer : " << *stringPTR << std::endl ;
    std::cout << "value of the ref : " << stringREF << std::endl ;
}
