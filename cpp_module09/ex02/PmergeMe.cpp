#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _count_com(0){}
PmergeMe::PmergeMe(std::string &cp) : expr(cp), _count_com(0){}
PmergeMe::PmergeMe(const PmergeMe &obj) : expr(obj.expr), _count_com(0){}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if(this != &obj)
		this->expr = obj.expr;
	return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::valid_expr()
{
	itstr it = expr.begin();
	for(; it != expr.end(); it++)
	{
		if(!std::isdigit(*it) && !std::isspace(*it))
			throw std::runtime_error("ERROR");
	}
}

void PmergeMe::compare_pairs(
	const std::vector<unsigned int>& input,
	std::vector<std::pair<unsigned int, unsigned int> >& pairs,
	bool& has_straggler,
	unsigned int& straggler)
{
	size_t i = 0;
	for (; i + 1 < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
	}

	has_straggler = (input.size() % 2 != 0);
	if (has_straggler)
		straggler = input.back();
}

void PmergeMe::large(
	std::vector<unsigned int>& S,
	const std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
	for (size_t i = 0; i < pairs.size(); ++i)
		S.push_back(pairs[i].first);
}

void binary_insert(std::vector<unsigned int>& chain, unsigned int value)
{
	std::vector<unsigned int>::iterator pos =
		std::lower_bound(chain.begin(), chain.end(), value);
	chain.insert(pos, value);
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

void PmergeMe::fordjohnson(std::vector<unsigned int>& data)
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

	fordjohnson(larger);

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
			binary_insert(main_chain, pend[idx]);
	}
	
	if (has_straggler)
		binary_insert(main_chain, straggler);
	
	data = main_chain;
}

void PmergeMe::get_data()
{
	std::stringstream ss(expr);
	long value;

	while (ss >> value)
	{
		if (value <= 0)
			throw std::runtime_error("ERROR");

		if (value > INT_MAX)
			throw std::runtime_error("ERROR");

		data.push_back(static_cast<int>(value));
	}

	if (data.empty())
		throw std::runtime_error("ERROR");
}

void PmergeMe::algo()
{
	fordjohnson(data);
}

void PmergeMe::printer()
{
	itvec it = data.begin();
	for(; it != data.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}