#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): target("home") , AForm("PresidentialPardonForm" , false , 25 , 5)
{
}


PresidentialPardonForm::PresidentialPardonForm(std::string const &tar): target(tar) , AForm("PresidentialPardonForm" , false , 25 , 5)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): target(obj.target) , AForm("PresidentialPardonForm" , false , 25 , 5)
{
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getgradetoExcute())
		throw AForm::GradeTooLowException();
	if (!this->getisSigned())
		throw AForm::GradeTooLowException();
	
	std::cout << this->target << "has been pardoned by Zaphod Beeblebrox." << std::endl ;
}

