#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try 
    {
        Bureaucrat *b = new Bureaucrat("simo" , 10);
        Form *a = new Form("form" , false , 2 , 20);
        b->signForm(*a);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl ;
    }
}