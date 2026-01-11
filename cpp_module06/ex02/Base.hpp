#pragma once



#include <string>
#include <iostream>
#include <cstdlib>

class Base
{
    public :
        virtual ~Base();
};


class A: public Base
{
    public :
        ~A();
}  ;


class B: public Base
{
    public :
        ~B();
}  ;


class C: public Base
{
    public :
        ~C();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);