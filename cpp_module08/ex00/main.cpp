
#include "easyfind.hpp"
#include <vector>
#include <list>
int main()
{
    std::list<int> vec;
    for (int i = 1; i <= 10; ++i)
        vec.push_back(i);
    try
    {
        std::list<int>::iterator it =  easyfind(vec , 4848);
        std::cout << "value found : " << *it << std::endl ;
    }
    catch (std::exception &e )
    {
        std::cout << e.what() << std::endl ;
    }

}


