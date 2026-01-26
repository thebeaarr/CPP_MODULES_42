#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <utility>

typedef std::vector<unsigned int>::iterator itvec;
typedef std::deque<unsigned int>::iterator itdeque;
typedef std::string::iterator itstr;

class PmergeMe
{
private:
	std::string expr;
	std::vector<unsigned int> data_vec;
	std::deque<unsigned int> data_deque;

	void valid_expr();
	void get_data();

	size_t jacobsthal(size_t n);
	std::vector<size_t> generate_jacobsthal_sequence(size_t n);

	void fordjohnson_vector(std::vector<unsigned int>& data);
	
	void fordjohnson_deque(std::deque<unsigned int>& data);

	void binary_insert_vector(std::vector<unsigned int>& chain, unsigned int value);
	
	void binary_insert_deque(std::deque<unsigned int>& chain, unsigned int value);

public:
	PmergeMe();
	PmergeMe(std::string &cp);
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	~PmergeMe();

	void algo();
	void print_before();
	void print_after();
};

#endif