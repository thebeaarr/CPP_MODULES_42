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
		std::cout << "Form Signed :)" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}





std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Name: " << obj.getName() << std::endl
	   << "Signed: " << obj.getisSigned() << std::endl
	   << "Grade to execute: " << obj.getgradetoExcute() << std::endl
	   << "Grade to sign: " << obj.getgradetoSign();
	return os;
}