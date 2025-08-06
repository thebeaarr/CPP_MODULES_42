#ifndef HUMANA_HPP
#define HUMANA_HPP


#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string namea;
        Weapon& wa;
    public:
        void attack();
        void setWeapon(Weapon &);
        HumanA(std::string , Weapon &);
        ~HumanA();
};



#endif
