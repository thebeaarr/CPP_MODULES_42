

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
Bureaucrat &Bureaucrat::operator=(const Bureaucrat&obj)
{
	if(this != &obj)
	{
		this->grade = obj.grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string const &name , int grade): name(name) , grade(grade)
{
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

const int &Bureaucrat::getGrade() const
{
	return this->grade;
}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException: to far from [0,150].";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: too far from [0,150].";
}

void Bureaucrat::DecGrade()
{
	this->grade++;
}

void Bureaucrat::IncGrade()
{
	this->grade--;
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}


void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << this->getName() << "  Can't Sign " << f.getName() << " because " << e.what()<< std::endl;
	} 
}


void Bureaucrat::executeForm(AForm const & form) const
{
	try 
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl ;
	}
	catch(...)
	{
		std::cout << this->getName() << " Couldn't excute " << form.getName() << std::endl ;
	}
}

