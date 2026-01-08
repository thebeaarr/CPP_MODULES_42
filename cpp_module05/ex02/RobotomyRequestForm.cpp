#include "RobotomyRequestForm.hpp"




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



void RobotomyRequestForm::execute(Bureaucrat const & executor)  const
{
	if (executor.getGrade() > this->getgradetoExcute())
		throw AForm::GradeTooLowException();
	if (!this->getisSigned())
		throw AForm::GradeTooLowException();
	
	std::cout << "* drilling noises *" << std::endl ;
	// making it random to just show even 50% success or failed 
	// and write this.target has been robotomized  successfully 50% of the time
	// or failed anyway
}

