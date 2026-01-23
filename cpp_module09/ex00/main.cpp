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
        DB db(av[1]);
        db.valid_key();
        // db.printer();
    

    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl ;
    }
}