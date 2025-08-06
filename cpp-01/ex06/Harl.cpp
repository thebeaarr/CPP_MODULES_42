#include "Harl.hpp"
void Harl::debug()
{
    std::cout << "[DEBUG]:I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]: think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout <<"[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int i = 0;
    std::string lvls[4] = {"DEBUG"  , "INFO" , "WARNING" , "ERROR"};
    void (Harl::*fonctions[])() = {&Harl::debug , &Harl::info , &Harl::warning, &Harl::error};
    for(; i < 4 ; i++)
    {
        if(level == lvls[i])
            break ;
    }

    switch(i)
    {
        case 0:
            (this->*fonctions[0])();
        case 1:
            (this->*fonctions[1])();
        case 2:
            (this->*fonctions[2])();
        case 3:
            (this->*fonctions[3])();
            break;
        default :
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
