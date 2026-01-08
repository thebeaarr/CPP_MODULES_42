
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat *c  = new Bureaucrat("medo" , 10);
		ShrubberyCreactionForm form("Bender");
		form.beSigned(*c);
		form.execute(*c);
	}

	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch(Bureaucrat::GradeTooLowException &e )
	{
		std::cout << e.what();
	}
	catch(AForm::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl ;
	}
}