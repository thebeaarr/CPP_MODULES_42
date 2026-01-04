#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
    private:
        std::string const name ;
       int grade; 
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat(const std::string & name, int gade);
        ~Bureaucrat();

        class GradeTooHighException: public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return  std::string("GradeTooHighException: too cold!").c_str();
                }
        };

        class GradeTooLowException : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return std::string("GradeTooHighException: too cold!").c_str();
                }
        };
        void signForm(Form &f);
        void IncGrade(); 
        void DecGrade();
        const std::string &getName() const;
        const int &getGrade() const;
};

std::ostream &operator<<(std::ostream &os , Bureaucrat  &obj);
#endif