#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		delete brain ;
		brain = new Brain(*other.brain);
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog bark" << std::endl;
}
