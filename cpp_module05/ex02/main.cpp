
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat *c  = new Bureaucrat("medo" , 1);
		ShrubberyCreactionForm form;
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
		std::cout << e.what() ;
	}
}