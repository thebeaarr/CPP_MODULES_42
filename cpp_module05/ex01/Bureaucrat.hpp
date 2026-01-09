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
		Bureaucrat &operator=(const Bureaucrat &obj);
		class GradeTooHighException: public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		void signForm(Form &f);
		void IncGrade(); 
		void DecGrade();
		const std::string &getName() const;
		const int &getGrade() const;
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif