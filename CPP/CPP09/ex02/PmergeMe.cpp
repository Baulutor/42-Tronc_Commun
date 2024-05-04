//
// Created by dbaule on 5/1/24.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(PmergeMe &src)
{
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe &rhs)
{
	if (this != &rhs)
	{

	}
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

// Method
bool	PmergeMe::pushVec(std::string buf)
{
	long tmp = atol(buf.c_str());
	if (((tmp == 0 || tmp == -1) && buf.size() > 1) || tmp < 0 || tmp > INT_MAX)
	{
		std::cout << "Error: put only numbers at int size, under INT_MAX = " << INT_MAX << std::endl;
		return (1);
	}
	this->_vecTab.push_back(tmp);
	return (0);
}

bool	PmergeMe::parsing(int argc, char **argv)
{
	if (argc <= 2)
	{
		std::cout << "Error: at least two argument is required to launch the program" << std::endl;
		return (1);
	}
	_size = argc - 1;
	for (size_t i = 1; argv[i]; i++)
	{
		std::string buf = argv[i];
		if (buf.find_first_not_of("0123456789") != buf.npos)
		{
			std::cout << "Error: wrong input, please put only numbers, without any sign (negative numbers cannot exist)" << std::endl;
			return (1);
		}
		if (this->pushVec(buf) == 1)
			return (1);
	}
	for (std::vector<int>::iterator it = _vecTab.begin(); it < _vecTab.end(); it++)
	{
		std::vector<int>::iterator ite = (it + 1);
		int buf = *it;
		while (ite < _vecTab.end())
		{
			if (buf == *ite)
			{
				std::cout << "Error: No double is allowed in the program" << std::endl;
				return (1);
			}
			ite++;
		}
	}
	return (0);
}

void	PmergeMe::sortBigPair()
{
	size_t count = 0;
	for (std::vector<int>::iterator it = _vecTab.begin(); it < _vecTab.end(); it++)
	{
		if (_size > count + 1 && count % 2 == 0)
		{
			if (*it > *(it + 1))
				std::swap(*it, *(it + 1));
		}
		count++;
	}
	for (std::vector<int>::iterator it = _vecTab.begin(); it < _vecTab.end(); it++)
	{
		std::vector<int>::iterator next;
		next = ++it;
		--it;
		_vecTabPair.push_back(std::make_pair(*it, *next));
		_vecTabBiggestPerPair.push_back(*next);
		_vecTab.erase(next);
	}
	this->mergeSort(_vecTabBiggestPerPair, 0, _vecTabBiggestPerPair.size() - 1);

	for (std::vector<std::pair<int, int> >::iterator it = _vecTabPair.begin(); it != _vecTabPair.end(); it++)
	{
		if (it->second == _vecTabBiggestPerPair[0])
		{
			if (it->second != it->first)
			{
				_vecTabBiggestPerPair.insert(_vecTabBiggestPerPair.begin(), it->first);
				for (std::vector<int>::iterator itVecTab = _vecTab.begin(); itVecTab != _vecTab.end(); itVecTab++)
				{
					if (*itVecTab == it->first)
					{
						_vecTab.erase(itVecTab);
						break;
					}
				}
			}
		}
	}
	// Maintenant je dois inserer ce qu'il reste !
	for (std::vector<int>::iterator it = _vecTab.begin(); it != _vecTab.end(); it++)
	{
		std::cout << "vec : " << (*it) << std::endl;
	}

}

int PmergeMe::jacobsthal(int n)
{
	int pos[n + 1];
	pos[0] = 0;
	pos[1] = 1;
	for (int i = 2; i <= n; i++)
		pos[i] = pos[i - 1] + 2 * pos[i - 2];
	return pos[n];
}

void	PmergeMe::sortJacob()
{

}

void PmergeMe::mergeSort(std::vector<int>& _vecTabBiggestPerPair, size_t left, size_t right) {
	if (left < right) {
		size_t middle = left + (right - left) / 2;
		mergeSort(_vecTabBiggestPerPair, left, middle);
		mergeSort(_vecTabBiggestPerPair, middle + 1, right);
		merge(_vecTabBiggestPerPair, left, middle, right);
	}
}

void PmergeMe::merge(std::vector<int>& _vecTabBiggestPerPair, size_t left, size_t middle, size_t right) {
	size_t i, j, k;
	size_t n1 = middle - left + 1;
	size_t n2 = right - middle;

	std::vector<int> L(n1), R(n2);

	for (i = 0; i < n1; i++)
		L[i] = _vecTabBiggestPerPair[left + i];
	for (j = 0; j < n2; j++)
		R[j] = _vecTabBiggestPerPair[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			_vecTabBiggestPerPair[k] = L[i];
			i++;
		} else {
			_vecTabBiggestPerPair[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		_vecTabBiggestPerPair[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		_vecTabBiggestPerPair[k] = R[j];
		j++;
		k++;
	}
}
