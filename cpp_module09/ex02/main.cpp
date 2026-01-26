#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe [positive integers...]" << std::endl;
		std::cerr << "Example: ./PmergeMe 3 5 9 7 4" << std::endl;
		return 1;
	}

	try
	{
		std::string input;
		for (int i = 1; i < argc; i++)
		{
			if (i > 1)
				input += " ";
			input += argv[i];
		}

		PmergeMe sorter(input);
		sorter.algo();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}