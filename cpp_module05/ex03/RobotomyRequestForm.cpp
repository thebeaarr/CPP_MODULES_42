#include "RobotomyRequestForm.hpp"

#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm() :AForm("RobotomyRequestForm" , false , 72 , 45)
{
	this->target = "home";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &targetc) :  AForm("RobotomyRequestForm" , false , 72 , 45)
{
	this->target = targetc;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) :  AForm("RobotomyRequestForm" , false , 72 , 45)
{
	this->target = obj.target ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if(this != &obj)
	{
		this->target = obj.target;
	}
	return *this ;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor)  const
{
	if (executor.getGrade() > this->getgradetoExcute())
		throw AForm::GradeTooLowException();
	if (!this->getisSigned())
		throw AForm::GradeTooLowException();
	
	std::cout << "* drilling noises *" << std::endl ;
	std::srand(time(0));
	if(rand() % 2 )
	{
		std::cout << this->target << " has been robotomized successfully 50\% of the time" << std::endl ;
	}
	else
		std::cout << "the robotomy failed" << std::endl ;
}
