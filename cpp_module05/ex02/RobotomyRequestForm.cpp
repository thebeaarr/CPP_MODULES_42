#include "RobotomyRequestForm.hpp"




RobotomyRequestForm::RobotomyRequestForm() : target("home") , AForm("RobotomyRequestForm" , false , 72 , 45)
{
	
}
RobotomyRequestForm::RobotomyRequestForm(std::string const &targetc) : target(targetc) , AForm("RobotomyRequestForm" , false , 72 , 45)
{
	
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : target(obj.target) , AForm("RobotomyRequestForm" , false , 72 , 45)
{
	
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

