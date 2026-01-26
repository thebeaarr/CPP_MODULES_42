#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(char *str)
{
    csv_loader();
    process_input(str);
}


BitcoinExchange::BitcoinExchange(){csv_loader();}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) : database(obj.database){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if(&obj != this)
        this->database = obj.database ;
    return *this ;
}


void BitcoinExchange::csv_loader()
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


void BitcoinExchange::trim(std::string &s)
{
    std::size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
        ++start;
    std::size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
        --end;
    s = s.substr(start, end - start);
}
void BitcoinExchange::printer()
{                           
    std::cout << "date      |  value" << std::endl ;
    for(itmap it = database.begin(); it != database.end() ; ++it)
    {
        std::cout << it->first << " " << it->second << std::endl ;
    }
}

BitcoinExchange::~BitcoinExchange(){}




void BitcoinExchange::valid_key()
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
            throw std::runtime_error("ERROR: invalid key    : '" + it->first + "'");

        int days_in_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(DD > days_in_month[MM -1 ] || DD < 1  )
        {
            throw std::runtime_error("ERROR: invalid key    : '" + it->first + "'");
        }
    }
}


void BitcoinExchange::process_input(char *str)
{
    std::ifstream input(str);
    std::string line ;
    if(!input.is_open())
    {
        std::cout << "Error: could not open file." << std::endl ;
        return ;
    }
    while(std::getline(input , line ))
    {
        if(line.empty())
            continue ;
        std::stringstream ss(line);
        std::string date ;
        std::string value ; 
        if(!std::getline(ss,  date , '|'))
        {
            std::cerr << "ERROR: bad input => " << line << std::endl ;
            continue ;
        }
        if(!std::getline(ss ,value ))
        {
            std::cerr << "ERROR: bad input => " << date  << std::endl ;
            continue ;
        }
        trim(value);
        trim(date);
        if(value == "value"  && date == "date")
            continue ;
        if(!date_parse(std::stringstream(date)))
            continue;
        double val = std::strtod(value.c_str() , NULL);
        if(val < 0 )
        {
            std::cerr<< "ERROR: not a positive number" << std::endl;
            continue ;
        }
        if(val > 1000)
        {
            std::cerr << "ERROR: too large a number" << std::endl ;
            continue ;
        }
        itmap it = database.upper_bound(date);
        
        if (it == database.begin())
        {
            std::cerr << "ERROR: no earlier date available" << std::endl;
            continue;
        }
        --it;
        std::cout << date << " => " << value << " = " << it->second * val << std::endl;
    }
}

bool BitcoinExchange::date_parse(std::stringstream ss)
{
    int YYYY , DD , MM ;
    char  dash1 , dash2 , extra;
    if (!(ss >> YYYY >> dash1 >> MM >> dash2 >> DD) || 
        dash1 != '-' || dash2 != '-' || (ss >> extra))
    {
        std::cerr << "ERROR: invalid key" << std::endl ;
        return false;
    }
    if(YYYY < 2009 || (YYYY == 2009 && MM == 1 && DD < 3) || (MM < 1 || MM > 12 ))
    {
        std::cerr << "ERROR: invalid key" << std::endl ;
        return false;
    }
        
    int days_in_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(DD > days_in_month[MM -1 ] || DD < 1  )
    {
        std::cerr << "ERROR: invalid key" << std::endl ;
        return false;
    }
    return true ;
}


