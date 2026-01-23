#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include <ostream>
#include <sstream>
#include "BitcoinExchange.hpp"
int main(int ac , char **av)
{

    try
    {
         BitcoinExchange db(av[1]);
        db.valid_key();
    

    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl ;
    }
}