#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unkown") , grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade)
{

}

Bureaucrat::Bureaucrat(std::string const &name , int grade): name(name) , grade(grade)
{    
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
