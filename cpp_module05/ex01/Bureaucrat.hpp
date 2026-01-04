#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>


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
                virtual const char *what() const throw()
                {
                    return "GradeTooHighException: too cold!";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw()
                {
                    return "GradeTooHighException: too cold!";
                }
        };
        void IncGrade(); 
        void DecGrade();
        const std::string &getName() const;
        const int &getGrade() const;
};

std::ostream &operator<<(std::ostream &os , Bureaucrat  &obj);
#endif