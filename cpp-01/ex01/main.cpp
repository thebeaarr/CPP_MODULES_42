#include "Zombie.hpp"


int main()
{
    Zombie *obj = zombieHorde(5  , "mohamed");
    for(int i = 0 ; i < 5 ; i++)
        obj[i].announce();
    delete[] obj;
}
