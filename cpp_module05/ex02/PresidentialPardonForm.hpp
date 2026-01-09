#pragma once


#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string target ; 
	public : 
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const  &tar);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		virtual void execute(Bureaucrat const & executor)  const ;
};