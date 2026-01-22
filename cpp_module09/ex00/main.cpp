#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include <ostream>
#include <sstream>

int main()
{
    std::ifstream file("data.csv");
    if(!file.is_open())
    {
        std::cout << "Failed: not opened" << std::endl ;
        return 1;
    }
    std::map<std::string , std::string > map ; 
    std::string line ;
    while(std::getline(file , line ))
    {
        std::stringstream ss(line);
        std::string key, value ;

        if(!std::getline(ss , key, ','))
            continue ;

        if(!std::getline(ss , value))
            continue ; 

        if(key == "date" && value == "exchange_rate")
            continue ;
        // here we get the key and see if it's respecting the standard which is the YYYY-MM-DD
        int YYYY , DD , MM ;
        char  dash1 , dash2 ;
        std::stringstream ss1(key);
        ss1 >> YYYY >> dash1 >> MM >> dash2 >> DD ;
        std::cout << YYYY << dash1 << MM << dash2 << DD << std::endl ;
        if(dash1 != '-'  || dash2  != '-')
            std::cout << "invalid key" << std::endl ;

        // check the limits or check
        int days_in_month[] = {
    31, // Jan
    28, // Feb (special case)
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun
    31, // Jul
    31, // Aug
    30, // Sep
    31, // Oct
    30, // Nov
    31  // Dec
};
    if(MM < 1  || MM > 12 )
    {
        std::cout << MM << std::endl ;
        std::cout << "month invalid" << std::endl ;
return 1;
    }
    if(days_in_month[MM -1 ] < DD || DD < 1 )
    {
        std::cout << "day invalid" << std::endl ;
        return 1; 
    }
    // check range between now and then 
    if(YYYY < 2009)
    {
        std::cout << "fuck no the bitcoin founded in 2009 - 01 - 03" << std::endl ;
        return 1 ;
    }
    if(YYYY == 2009)
    {
        if(MM == 1)
        {
            if(DD < 3 )
            {
        std::cout << "fuck no the bitcoin founded in 2009 - 01 - 03" << std::endl ; 
                return 1 ;
            }
        }
    }
    
    map[key] = value;
    }

    
    for(std::map<std::string , std::string>::iterator it = map.begin() ; it != map.end() ; it++)
        std::cout << "key = " << it->first <<     " value = " << it->second << std::endl;

    // format is key = YYYY-MM-DD while YYYY [when excatly start - until now ( tracking the time current), January 3, 2009 (first ooccurency) and for the MM we know months can 
    // just exceed 1 and 12 , amd for DD can we find an algorithme to just use the exact max days in month ?? 

    // parse the time 

    for(std::map<std::string , std::string>::iterator it = map.begin() ; it != map.end() ; it++)
    {

    }
}