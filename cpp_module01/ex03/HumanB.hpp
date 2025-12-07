#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"
#include <string>

class HumanB
{
    private:
        std::string nameb;
        Weapon *wb;
    public:
        void attack();
        void setWeapon(Weapon &);
        HumanB(std::string , Weapon&);
        HumanB(std::string);
        ~HumanB();
};


#endif
