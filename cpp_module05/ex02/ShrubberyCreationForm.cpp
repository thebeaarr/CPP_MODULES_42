#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>
ShrubberyCreactionForm::ShrubberyCreactionForm() : target("home"),AForm("ShrubberyCreactionForm" , false , 145 , 137)
{
}

ShrubberyCreactionForm::ShrubberyCreactionForm(const std::string &tar): target(tar),AForm("ShrubberyCreactionForm" , false , 145 , 137)
{
	
}
ShrubberyCreactionForm::ShrubberyCreactionForm(const ShrubberyCreactionForm &obj): target(obj.target),AForm("ShrubberyCreactionForm" , false , 145 , 137)
{
}

ShrubberyCreactionForm::~ShrubberyCreactionForm()
{
}
void ShrubberyCreactionForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getgradetoExcute())
		throw AForm::GradeTooLowException();
	if (!this->getisSigned())
		throw AForm::GradeTooLowException();

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
