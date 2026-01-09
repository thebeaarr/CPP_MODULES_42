#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm() : name("unkown") ,gradetoExcute(0),gradetoSign(0) , isSigned(false)
{

}
AForm::AForm(AForm const &obj) : name(obj.getName()), gradetoExcute(obj.getgradetoExcute()), gradetoSign(obj.getgradetoSign()) ,isSigned(obj.getisSigned())
{
} 

AForm::AForm(std::string const &namec , bool isSignedc, int gradetoSignc , int gradetoExcutec) : name(namec) , gradetoExcute(gradetoExcutec) , gradetoSign(gradetoSignc), isSigned(isSignedc) 
{
}

AForm::~AForm()
{
}
const char *AForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException: Bureaucrat has less than the form required";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: Bureaucrat has less than the form required";
}

void AForm::beSigned(const Bureaucrat &obj)
{
	if(obj.getGrade() <= this->getgradetoSign())
	{
		this->isSigned = true;
		std::cout << this->getName() << "Signed :)" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "Name: " << obj.getName() << std::endl
	   << "Signed: " << obj.getisSigned() << std::endl
	   << "Grade to execute: " << obj.getgradetoExcute() << std::endl
	   << "Grade to sign: " << obj.getgradetoSign();
	return os;
}