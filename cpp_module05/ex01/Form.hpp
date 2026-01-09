#pragma once


#include <string>
#include <iostream>
#include <exception>
class Bureaucrat ;
class Form
{
	private:
		std::string const name; 
		int const gradetoExcute;
		int const gradetoSign;
		bool isSigned ;
	public:
		Form();
		Form(Form const &obj);
		Form(std::string const &name , bool isSigned , int gradetoSign, int gradetoExcute);
		~Form();
		Form &operator=(const Form &obj);
		class  GradeTooHighException : public std::exception 
		{
			public :
			virtual const char *what() const throw();
		};
		class GradeTooLowException: std::exception
		{
			public :
			virtual  const char *what() const throw();
		};

		void beSigned(const Bureaucrat &obj);
		const std::string &getName() const;
		const bool &getisSigned() const;
		const int &getgradetoExcute() const;
		const int &getgradetoSign() const;
};
std::ostream &operator<<(std::ostream &os, const Form &obj);
