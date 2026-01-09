#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class ShrubberyCreactionForm : public AForm
{
	private :
		std::string target ;
	public :
		ShrubberyCreactionForm();
		ShrubberyCreactionForm(const std::string &tar);
		ShrubberyCreactionForm(const ShrubberyCreactionForm &obj);
		~ShrubberyCreactionForm();
		ShrubberyCreactionForm &operator=(const ShrubberyCreactionForm &obj);

		virtual void execute(Bureaucrat const & executor)  const ;
};
