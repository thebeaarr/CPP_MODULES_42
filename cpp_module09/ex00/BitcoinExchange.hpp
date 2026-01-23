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
        void csv_loader()
        {

            std::ifstream file("data.csv");
            std::string line ;
            if (!file.is_open())
                throw std::runtime_error("ERROR: could not open data.csv");
            while (std::getline(file, line))
            {
                if (line.empty())
                    continue;

                std::stringstream ss(line);
                std::string key, value;

                if (!std::getline(ss, key, ','))
                    continue;

                if (!std::getline(ss, value))
                    throw std::runtime_error("ERROR: invalid line : '" + line + "'");

                if (key == "date" && value == "exchange_rate")
                    continue;

                if (value.empty())
                    throw std::runtime_error("ERROR: key or value empty");

                char *end;
                double save = std::strtod(value.c_str(), &end);
                if (*end != '\0')
                    throw std::runtime_error("ERROR: invalid key    : '" + key + "'");

                database[key] = save;
            }
            file.close();
        }

        void printer()
        {                           
            std::cout << "date      |  value" << std::endl ;
            for(itmap it = database.begin(); it != database.end() ; ++it)
            {
                std::cout << it->first << " " << it->second << std::endl ;
            }

        }
        void trim(std::string &s)
        {
            std::size_t start = 0;
            while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
                ++start;

            std::size_t end = s.size();
            while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
                --end;

            s = s.substr(start, end - start);
        }
        bool date_parse(std::stringstream ss);
        void process_input(char *str);
        BitcoinExchange(char *str);
        
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);

        BitcoinExchange &operator=(const BitcoinExchange &obj);

        ~BitcoinExchange();

        void valid_key();
};

