#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try 
	{
		Bureaucrat *b = new Bureaucrat("simo" , 2);
		Form a("forma" , false , 2 , 20);
		b->signForm(a);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl ;
	}
}