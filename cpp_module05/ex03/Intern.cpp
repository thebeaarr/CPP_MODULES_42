#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern &obj) 
{
	(void)obj;
}
AForm *Intern::makeForm(std::string const &form , std::string const &target)
{
	std::string validform[] = {"PresidentialPardonForm" ,"ShrubberyCreationForm" , "RobotomyRequestForm" }; 
	int i = 0 ;
	for(; i < 3 ; i++)
	{
		if(validform[i] == form)
			break ;
	}
	AForm *forma ;
	switch(i)
	{
		case 0 : 
			forma = new ShrubberyCreactionForm(target);
			break;
		case 1 :
			forma = new PresidentialPardonForm(target);
		break;
		case 2:
			forma = new RobotomyRequestForm(target);
		break;
		default:
			throw Intern::FormNotFoundException();
		break ;
	}
	std::cout << "Intern create  " <<form << std::endl ;
	return forma ;
}

