#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
	const WrongAnimal* meta = new WrongCat();
	meta->makeSound();
	delete meta;
	return 0;
}