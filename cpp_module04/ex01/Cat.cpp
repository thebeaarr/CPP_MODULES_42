#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
		Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat meow" << std::endl;
}
