#include "Harl.hpp"


int main(int ac , char **av)
{
    Harl harl ;
    (void)ac;
    if(av[1] == NULL)
        std::cout << "word empty" << std::endl;
    else
        harl.complain(av[1]);
}
