#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}

A::~A()
{
    std::cout << "A destructor called" << std::endl;
}

B::~B()
{
    std::cout << "B destructor called" << std::endl;
}

C::~C()
{
    std::cout << "C destructor called" << std::endl;
}

Base* generate()
{
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(0));
        seeded = true;
    }

    int r = std::rand() % 3;

    if (r == 0)
        return new A;
    if (r == 1)
        return new B;
    return new C;
}

void identify(Base* p)
{
    if (!p)
    {
        std::cout << "Null pointer" << std::endl;
        return;
    }

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "Unknown type" << std::endl;
}
