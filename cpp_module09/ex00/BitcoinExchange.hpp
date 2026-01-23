#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include <ostream>
#include <sstream>





// class CsvParser
// {
//     private :
//         CsvParser(); 
//         CsvParser(const CsvParser &obj ); 
//         ~CsvParser();
//         CsvParser &operator=(const CsvParser &obj);
//         static const std::ifstream  file;
        
//     public:
// };
#include <cstdlib>
class DB
{
    private :
        std::map<std::string , double> database;
        std::map<std::string , double> db1 ;

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
        void input_loader(char *str)
        {
            std::ifstream input(str); 
            std::string line ;
            if(!input.is_open())    
                
        }
        DB(char *str)
        {
            csv_loader();
            input_loader(str);   
        }
        
        DB(){csv_loader();};
        DB(const DB &obj) : database(obj.database)
        {
        }

        DB &operator=(const DB &obj)
        {
            if(&obj != this)
                this->database = obj.database ;
            return *this ;
        }

        ~DB(){}

        void valid_key()
        {
            for(itmap it = database.begin() ; it  != database.end() ; ++it )
            {
                std::stringstream ss(it->first);
                int YYYY , DD , MM ;
                char  dash1 , dash2 , extra;
                if (!(ss >> YYYY >> dash1 >> MM >> dash2 >> DD) || 
                    dash1 != '-' || dash2 != '-' || (ss >> extra))
                {
                    throw std::runtime_error("ERROR: invalid key    : '" + it->first + "'");
                }
                if(YYYY < 2009 || (YYYY == 2009 && MM == 1 && DD < 3) || (MM < 1 || MM > 12 ))
                    throw std::runtime_error("ERROR: invalid key    : '" + it->first+ "'");
        
                int days_in_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                if(DD > days_in_month[MM -1 ] || DD < 1  )
                {
                    throw std::runtime_error("ERROR: invalid key    : '" + it->first + "'");
                }
            }
        }

        // void valid_value()
        // {
        //     for(itmap it = database.begin() ; it != database.end();++it)
        //     {
        //         if(it->second > 1000 || it->second < 0)
        //         {
        //             std::cout << it->first  << "," << it->second << std::endl ;
        //             throw std::runtime_error("ERROR: invalid value");
        //         }
        //     }
        // }
};

