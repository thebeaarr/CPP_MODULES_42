#include <iostream>
#include "Point.hpp"

int main()
{
    // Define triangle ABC
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    // Points to test
    Point inside(3, 3);
    Point outside(11, 5);
    Point edge(5, 0);

    std::cout << std::boolalpha; // print true/false instead of 1/0

    std::cout << "Point (3,3) inside?   " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point (11,5) inside?  " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Point (5,0) inside?   " << bsp(a, b, c, edge) << std::endl;

    return 0;
}
