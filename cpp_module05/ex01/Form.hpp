#pragma once


#include <string>
#include <iostream>
#include <exception>

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
        class  GradeTooHighException : public std::exception 
        {
            virtual char *what() const throw()
            {
                return "GradeTooHighException:too cold!";
            }
        };
        class GradeTooLowException: std::exception
        {
            virtual char *what() const throw()
            {
                return "GradeTooLowException: too cold!";
            }
        };
    const std::string &getName() const {return this->name ;}
    const bool &getisSigned() const {return this->isSigned ;}
    const int &getgradetoExcute() const {return this->gradetoExcute;}
    const int &getgradetoSign() const {return this->gradetoSign;}
};

std::ostream &operator <<(std::ostream os , Form obj)
{
    os << "Name : "<<  obj.getName() << std::endl << "isSigned : " << obj.getisSigned() <<std::endl << "grade to Excute : " << obj.getgradetoExcute() <<std::endl << "grade to Signed : " << obj.getgradetoSign()<< ".";
}