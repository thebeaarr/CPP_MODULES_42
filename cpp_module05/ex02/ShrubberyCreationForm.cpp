#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>
ShrubberyCreactionForm::ShrubberyCreactionForm() : AForm("ShrubberyCreactionForm" , false , 145 , 137)
{
	this->target = "home";
}

ShrubberyCreactionForm::ShrubberyCreactionForm(const std::string &tar):AForm("ShrubberyCreactionForm" , false , 145 , 137)
{
	this->target = tar;
}
ShrubberyCreactionForm::ShrubberyCreactionForm(const ShrubberyCreactionForm &obj):AForm("ShrubberyCreactionForm" , false , 145 , 137)
{
	this->target = obj.target;
}

ShrubberyCreactionForm::~ShrubberyCreactionForm()
{
}
void ShrubberyCreactionForm::execute(Bureaucrat const & executor) const
{
	std::cout << "--" << executor.getGrade() << std::endl ;
	std::cout << this->getgradetoExcute() << std::endl ;
	if (executor.getGrade() > this->getgradetoExcute())
		throw AForm::GradeTooLowException();
	if (!this->getisSigned())
		throw AForm::GradeTooLowException();
	
	std::cout << "same" << std::cout ;
	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to open shrubbery output file");

	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  //\n";
	file << "   ~~  \\ //  ~~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\     \n";
	// file << "       *        \n";
	// file << "      ***        \n" ;
	// file << "     *****        \n";
	// file << "    *******        \n";
	// file << "   *********        \n" ;
	// file << "      |||           \n";
	// file << "      |||            \n" ;
	file.close();
}
