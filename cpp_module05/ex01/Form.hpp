#pragma once


#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat ;
class Form
{
    private:
        std::string const name; 
        bool isSigned ;
        int const gradetoSign ;
        int const gradetoExcute;
    public:
        Form();
        Form(Form const &obj);
        Form(std::string const &name , bool isSigned , int gradetoSign, int gradetoExcute);
        ~Form();
        class  GradeTooHighException : public std::exception 
        {
            public : virtual char *what() const throw()
            {
                return "GradeTooHighException:too cold!";
            }
        };
        class GradeTooLowException: std::exception
        {
           public : virtual char *what() const throw()
            {
                return "GradeTooLowException: too cold!";
            }
        };
        void beSigned(const Bureaucrat &obj);
        const std::string &getName() const {return this->name ;}
        const bool &getisSigned() const {return this->isSigned ;}
        const int &getgradetoExcute() const {return this->gradetoExcute;}
        const int &getgradetoSign() const {return this->gradetoSign;}
};

std::ostream &operator <<(std::ostream &os , Form &obj)
{
    os << "Name : "<<  obj.getName() << std::endl << "isSigned : " << obj.getisSigned() <<std::endl << "grade to Excute : " << obj.getgradetoExcute() <<std::endl << "grade to Signed : " << obj.getgradetoSign()<< ".";
    return os;
}