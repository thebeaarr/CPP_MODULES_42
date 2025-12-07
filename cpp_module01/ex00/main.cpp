#include "Zombie.hpp"

int main()
{
    Zombie *z = newZombie("Heap");
    z->announce();
    randomChump("stack");
    delete z; 
}
