#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form() : name("unkown") ,gradetoExcute(0),gradetoSign(0) , isSigned(false)
{

}
Form::Form(Form const &obj) : name(obj.getName()), gradetoExcute(obj.getgradetoExcute()), gradetoSign(obj.getgradetoSign()) ,isSigned(obj.getisSigned())
{
} 

Form::Form(std::string const &namec , bool isSignedc, int gradetoSignc , int gradetoExcutec) : name(namec) , gradetoExcute(gradetoExcutec) , gradetoSign(gradetoSignc), isSigned(isSignedc) 
{
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat &obj)
{
	if(obj.getGrade() <= this->getgradetoSign())
	{
		this->isSigned = true;
		std::cout << this->getName() << " Signed :)" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

Form &Form::operator=(const Form &obj)
{
	if(this != &obj)
	{
		this->isSigned = obj.isSigned ;
	}
	return *this ;
}

const std::string &Form::getName() const {return this->name ;}
const bool &Form::getisSigned() const {return this->isSigned ;}
const int &Form::getgradetoExcute() const {return this->gradetoExcute;}
const int &Form::getgradetoSign() const {return this->gradetoSign;}

const char *Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException: Bureaucrat has more than the form required";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: Bureaucrat has less than the form required";
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Name: " << obj.getName() << std::endl
	   << "Signed: " << obj.getisSigned() << std::endl
	   << "Grade to execute: " << obj.getgradetoExcute() << std::endl
	   << "Grade to sign: " << obj.getgradetoSign();
	return os;
}