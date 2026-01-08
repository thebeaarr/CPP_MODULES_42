#pragma once


#include <string>
#include <iostream>
#include <exception>
class Bureaucrat ;
class AForm
{
	private:
		std::string const name; 
		int const gradetoExcute;
		int const gradetoSign;
		bool isSigned ;
	public:
		AForm();
		AForm(AForm const &obj);
		AForm(std::string const &name , bool isSigned , int gradetoSign, int gradetoExcute);
		virtual ~AForm();
		class  GradeTooHighException : public std::exception 
		{
			public :
			virtual const char *what() const throw()
			{
				return "GradeTooHighException: too cold!";
			}
		};
		class GradeTooLowException: std::exception
		{
			public : virtual  const char *what() const throw()
			{
				return "GradeTooLowException: too cold!";
			}
		};
		virtual void  execute(Bureaucrat const & executor)  const = 0;
		void beSigned(const Bureaucrat &obj);
		const std::string &getName() const {return this->name ;}
		const bool &getisSigned() const {return this->isSigned ;}
		const int &getgradetoExcute() const {return this->gradetoExcute;}
		const int &getgradetoSign() const {return this->gradetoSign;}
};
std::ostream &operator<<(std::ostream &os, const AForm &obj);
