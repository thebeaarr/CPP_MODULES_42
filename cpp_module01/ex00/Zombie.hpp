#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private :
        std::string name;
    public:
        void setName(std::string);
        std::string getName( void );
        void announce( void );
        Zombie();
        Zombie(std::string);
        ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
