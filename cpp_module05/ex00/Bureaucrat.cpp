#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unkown") , grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade)
{
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(std::string const &name , int grade): name(name) , grade(grade)
{
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat&obj)
{
	if(this != &obj)
	{
		this->grade = obj.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException: to far from [0,150].";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: too far from [0,150].";
}

const int &Bureaucrat::getGrade() const
{
	return this->grade;
}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

void Bureaucrat::DecGrade()
{
	this->grade++;
}

void Bureaucrat::IncGrade()
{
    this->grade--;
}

std::ostream &operator<<(std::ostream &os , Bureaucrat &obj)
{
    os << obj.getName() << " , bureaucrat grade " << obj.getGrade() << "." ;
    return os ;
}
