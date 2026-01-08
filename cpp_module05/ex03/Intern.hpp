#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
class Intern
{
	public :
		Intern();
		Intern(const Intern &obj);
		~Intern();
		class FormNotFoundException:public  std::exception 
		{
			virtual char const *what() const throw()
			{
				return "Intern Error: Form not found";
			}
		};
		AForm *makeForm(std::string const &form, std::string const &target );
};