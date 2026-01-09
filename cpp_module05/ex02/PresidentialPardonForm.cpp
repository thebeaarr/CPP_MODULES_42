#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():  AForm("PresidentialPardonForm" , false , 25 , 5)
{
	this->target  = "home";
}



PresidentialPardonForm::PresidentialPardonForm(std::string const &tar): AForm("PresidentialPardonForm" , false , 25 , 5)
{
	this->target  = tar;
	
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm("PresidentialPardonForm" , false , 25 , 5)
{
	this->target  = obj.target;
	
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if(this != &obj)
	{
		this->target = obj.target;
	}
	return *this ;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getgradetoExcute())
		throw AForm::GradeTooLowException();
	if (!this->getisSigned())
		throw AForm::GradeTooLowException();
	
	std::cout << this->target << "has been pardoned by Zaphod Beeblebrox." << std::endl ;
}


PresidentialPardonForm::~PresidentialPardonForm(){}
