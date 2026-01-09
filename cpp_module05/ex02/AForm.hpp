#pragma once


#include <string>
#include <iostream>
#include <exception>
class Bureaucrat ;
class AForm
{
	private:
		std::string const name; 
		const int  gradetoExcute;
		const int  gradetoSign;
		bool isSigned ;
	public:
		AForm();
		AForm(AForm const &obj);
		AForm &operator=(const AForm &obj);
		AForm(std::string const &name , bool isSigned , int gradetoSign, int gradetoExcute);
		virtual ~AForm();
		class  GradeTooHighException : public std::exception 
		{
			public :
			virtual const char *what() const throw();
		};
		class GradeTooLowException: std::exception
		{
			public :
			virtual  const char *what() const throw()
			{
				return "GradeTooHighException: Bureaucrat has less than the form required";
			}
		};
		virtual void  execute(Bureaucrat const & executor)  const = 0;
		void beSigned(const Bureaucrat &obj);
		const std::string &getName() const ;
		bool getisSigned() const ;
		int getgradetoExcute() const;
		int getgradetoSign() const;
};
std::ostream &operator<<(std::ostream &os, const AForm &obj);
