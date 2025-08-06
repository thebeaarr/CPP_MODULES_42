#include "Zombie.hpp"

int main()
{
    Zombie *objZombie = newZombie("Heap_Zombie");
    objZombie->announce();
    randomChump("Stack_Zombie");
    delete objZombie;
}
