#include "Intern.hpp"
int main()
{
	
	try 
	{
		Intern someRandomIntern  ;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		(void)rrf;
	}
	catch (...)
	{
		std::cout << "nichan" << std::endl ;
	}
}