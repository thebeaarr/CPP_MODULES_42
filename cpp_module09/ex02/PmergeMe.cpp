#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string &cp) : expr(cp) {}

PmergeMe::PmergeMe(const PmergeMe &obj) : expr(obj.expr) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
		this->expr = obj.expr;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::valid_expr()
{
	itstr it = expr.begin();
	for (; it != expr.end(); it++)
	{
		if (!std::isdigit(*it) && !std::isspace(*it))
			throw std::runtime_error("ERROR: Invalid character in input");
	}
}

void PmergeMe::get_data()
{
	std::stringstream ss(expr);
	long value;

	while (ss >> value)
	{
		if (value <= 0)
			throw std::runtime_error("ERROR: Negative or zero values not allowed");

		if (value > INT_MAX)
			throw std::runtime_error("ERROR: Value exceeds maximum integer");

		data_vec.push_back(static_cast<unsigned int>(value));
		data_deque.push_back(static_cast<unsigned int>(value));
	}

	if (data_vec.empty())
		throw std::runtime_error("ERROR: No valid input provided");
}

size_t PmergeMe::jacobsthal(size_t n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	
	size_t a = 0;
	size_t b = 1;
	
	for (size_t i = 2; i <= n; i++)
	{
		size_t temp = b + 2 * a;
		a = b;
		b = temp;
	}
	return b;
}

std::vector<size_t> PmergeMe::generate_jacobsthal_sequence(size_t n)
{
	std::vector<size_t> sequence;
	
	if (n == 0)
		return sequence;
	
	sequence.push_back(0);
	
	if (n == 1)
		return sequence;
	
	size_t jacob_idx = 3;
	size_t prev_jacob = 1;
	
	while (prev_jacob < n)
	{
		size_t curr_jacob = jacobsthal(jacob_idx);
		
		if (curr_jacob >= n)
			curr_jacob = n;

		for (size_t i = curr_jacob - 1; i > prev_jacob - 1 && i < n; --i)
			sequence.push_back(i);

		if (curr_jacob >= n)
			break;

		prev_jacob = curr_jacob;
		jacob_idx++;
	}

	return sequence;
}


void PmergeMe::binary_insert_vector(std::vector<unsigned int>& chain, unsigned int value)
{
	std::vector<unsigned int>::iterator pos =
		std::lower_bound(chain.begin(), chain.end(), value);
	chain.insert(pos, value);
}

void PmergeMe::fordjohnson_vector(std::vector<unsigned int>& data)
{
	if (data.size() <= 1)
		return;
	bool has_straggler = (data.size() % 2 != 0);

	unsigned int straggler = has_straggler ? data.back() : 0;

	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	for (size_t i = 0; i + 1 < data.size(); i += 2)
	{
		if (data[i] > data[i + 1])
			pairs.push_back(std::make_pair(data[i], data[i + 1]));
		else
			pairs.push_back(std::make_pair(data[i + 1], data[i]));
	}

	if (pairs.empty())
		return;
	std::vector<unsigned int> larger;
	for (size_t i = 0; i < pairs.size(); ++i)
		larger.push_back(pairs[i].first);
	fordjohnson_vector(larger);

	std::vector<unsigned int> main_chain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first == larger[0])
		{
			main_chain.push_back(pairs[i].second);
			break;
		}
	}
	main_chain.insert(main_chain.end(), larger.begin(), larger.end());

	std::vector<unsigned int> pend;
	for (size_t i = 1; i < larger.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == larger[i])
			{
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}
	std::vector<size_t> insertion_sequence = generate_jacobsthal_sequence(pend.size());

	for (size_t i = 0; i < insertion_sequence.size(); ++i)
	{
		size_t idx = insertion_sequence[i];
		if (idx < pend.size())
			binary_insert_vector(main_chain, pend[idx]);
	}
	
	if (has_straggler)
		binary_insert_vector(main_chain, straggler);
	
	data = main_chain;
}


void PmergeMe::binary_insert_deque(std::deque<unsigned int>& chain, unsigned int value)
{
	std::deque<unsigned int>::iterator pos =
		std::lower_bound(chain.begin(), chain.end(), value);
	chain.insert(pos, value);
}

void PmergeMe::fordjohnson_deque(std::deque<unsigned int>& data)
{
	if (data.size() <= 1)
		return;

	bool has_straggler = (data.size() % 2 != 0);
	unsigned int straggler = has_straggler ? data.back() : 0;

	std::deque<std::pair<unsigned int, unsigned int> > pairs;
	for (size_t i = 0; i + 1 < data.size(); i += 2)
	{
		if (data[i] > data[i + 1])
			pairs.push_back(std::make_pair(data[i], data[i + 1]));
		else
			pairs.push_back(std::make_pair(data[i + 1], data[i]));
	}

	if (pairs.empty())
		return;

	std::deque<unsigned int> larger;
	for (size_t i = 0; i < pairs.size(); ++i)
		larger.push_back(pairs[i].first);

	fordjohnson_deque(larger);

	std::deque<unsigned int> main_chain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first == larger[0])
		{
			main_chain.push_back(pairs[i].second);
			break;
		}
	}

	main_chain.insert(main_chain.end(), larger.begin(), larger.end());

	std::deque<unsigned int> pend;
	for (size_t i = 1; i < larger.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == larger[i])
			{
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}

	std::vector<size_t> insertion_sequence = generate_jacobsthal_sequence(pend.size());

	for (size_t i = 0; i < insertion_sequence.size(); ++i)
	{
		size_t idx = insertion_sequence[i];
		if (idx < pend.size())
			binary_insert_deque(main_chain, pend[idx]);
	}
	
	if (has_straggler)
		binary_insert_deque(main_chain, straggler);
	
	data = main_chain;
}


void PmergeMe::algo()
{
	valid_expr();
	get_data();
	
	std::cout << "Before: ";
	print_before();
	
	clock_t start_vec = clock();
	fordjohnson_vector(data_vec);
	clock_t end_vec = clock();
	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
	
	clock_t start_deque = clock();
	fordjohnson_deque(data_deque);
	clock_t end_deque = clock();
	double time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "After:  ";
	print_after();
	
	std::cout << "Time to process a range of " << data_vec.size() 
	          << " elements with std::vector : " << time_vec << " us" << std::endl;
	
	std::cout << "Time to process a range of " << data_deque.size() 
	          << " elements with std::deque  : " << time_deque << " us" << std::endl;
}

void PmergeMe::print_before()
{
	std::stringstream ss(expr);
	unsigned int value;
	
	while (ss >> value)
		std::cout << value << " ";
	std::cout << std::endl;
}

void PmergeMe::print_after()
{
	itvec it = data_vec.begin();
	for (; it != data_vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}