#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("mohamed", 152);
		a.IncGrade();
		a.
		IncGrade();
		if(a.getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
		if(a.getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		std::cout << a << std::endl ;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "unexpcted hahaha" << std::endl ;
	}
	return 0;
}


// int main(){
// 	Bureaucrat a("mohamed" , 140);
// 	Bureaucrat *b ;
// 	b = &a ;
// 	Bureaucrat c ;
// 	c = a ;
// 	std::cout << c.getName() << std::endl  << b->getName()<< std::endl ;
// }