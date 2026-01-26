#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include <ostream>
#include <sstream>


#include <cstdlib>
class BitcoinExchange
{
    private :
        std::map<std::string , double> database;
        typedef        std::string::iterator itstr;
        typedef std::map<std::string , double>::iterator  itmap ;
    public:
        void csv_loader();
        void printer();
        void trim(std::string &s);
        bool date_parse(std::stringstream ss);
        void process_input(char *str);
        BitcoinExchange(char *str);
        
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);

        BitcoinExchange &operator=(const BitcoinExchange &obj);

        ~BitcoinExchange();

        void valid_key();
};

