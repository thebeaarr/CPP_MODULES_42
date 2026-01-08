#pragma once
#include "AForm.hpp"

#include "Bureaucrat.hpp"



class RobotomyRequestForm:public AForm
{
	
	
	private :
		std::string target ;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		~RobotomyRequestForm();

		virtual void execute(Bureaucrat const & executor)  const ;
};