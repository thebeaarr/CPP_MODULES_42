# pragma once 

# include <string>
# include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	Brain(const std::string &idea);
	Brain &operator=(const Brain &other);
	~Brain();
private:
	std::string ideas[100];
};
