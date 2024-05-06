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

// Getter

size_t	PmergeMe::getSize()
{
	return (_size);
}


// Method

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
		if (this->pushVecList(buf) == 1)
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
	std::cout << "Before:	";
	for (std::vector<int>::iterator it = _vecTab.begin(); it < _vecTab.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return (0);
}

bool	PmergeMe::pushVecList(std::string buf)
{
	long tmp = atol(buf.c_str());
	if (((tmp == 0 || tmp == -1) && buf.size() > 1) || tmp < 0 || tmp > INT_MAX)
	{
		std::cout << "Error: put only numbers at int size, under INT_MAX = " << INT_MAX << std::endl;
		return (1);
	}
	this->_vecTab.push_back(tmp);
	this->_lstInt.push_back(tmp);
	return (0);
}

// Method Vector

void	PmergeMe::sortBigPairVec()
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
		_vecTabPair.push_back(std::make_pair(*it, *(it + 1)));
		_vecTabBiggestPerPair.push_back(*(it + 1));
		_vecTab.erase(it + 1);
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
	sortJacob();
	// Maintenant je dois inserer ce qu'il reste !


	std::cout << "After: ";
	for (std::vector<int>::iterator it = _vecTabBiggestPerPair.begin(); it != _vecTabBiggestPerPair.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

}

void	PmergeMe::sortJacob()
{
	std::vector<int> jacob = this->jacobsthal(_size);
//	std::vector<int>::iterator itTab = _vecTab.begin();
//	std::vector<int>::iterator left = _vecTabBiggestPerPair.begin();
//	std::vector<int>::iterator right = _vecTabBiggestPerPair.end();
	insertJohnson(jacob);
}
std::vector<int> PmergeMe::jacobsthal(int n)
{
	std::vector<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	for (int i = 2; i <= n; i++)
		jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
	return jacob;
}


void	PmergeMe::insertJohnson(std::vector<int> jacob)
{
	for (std::vector<int>::iterator it = _vecTab.begin(); it < _vecTab.end(); it++)
	{
		int left = 0;
		int right = _vecTabBiggestPerPair.size() - 1;
//		std::cout << right << std::endl;
//		std::cout << _vecTabBiggestPerPair[right] << " Test" << std::endl;
		this->insert(it, jacob, left, right);
	}
}

void	PmergeMe::insert(std::vector<int>::iterator it, std::vector<int> jacob, int left, int right)
{
	int mid = (right + left) / 2;
	(void)jacob;
	if ((*it > _vecTabBiggestPerPair[mid] && *it < _vecTabBiggestPerPair[mid + 1]) ||  mid == 0)
	{
		std::vector<int>::iterator pos = _vecTabBiggestPerPair.begin() + mid;
		if (mid == 0)
		{
			if (*it > _vecTabBiggestPerPair[mid])
				_vecTabBiggestPerPair.insert(pos + 1, *it);
			else
				_vecTabBiggestPerPair.insert(pos, *it);
		}
		else
			_vecTabBiggestPerPair.insert(pos + 1, *it);
	}
	else if (*it < _vecTabBiggestPerPair[mid])
	{
		right = mid;
		this->insert(it, jacob, left, right);
	}
	else if (*it > _vecTabBiggestPerPair[mid])
	{
		left = mid;
		this->insert(it, jacob, left, right);
	}
}

void PmergeMe::mergeSort(std::vector<int>& _vecTabBiggestPerPair, size_t left, size_t right) {
	if (left < right) {
		size_t middle = left + (right - left) / 2;
		mergeSort(_vecTabBiggestPerPair, left, middle);
		mergeSort(_vecTabBiggestPerPair, middle + 1, right);
		merge(_vecTabBiggestPerPair, left, middle, right);
	}
}

void PmergeMe::merge(std::vector<int>& _vecTabBiggestPerPair, size_t left, size_t middle, size_t right)
{
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

// Method list

void	PmergeMe::sortBigPairLst()
{
	size_t count = 0;
	for (std::list<int>::iterator it = _lstInt.begin(); it != _lstInt.end(); it++)
	{
		std::list<int>::iterator  next = ++it;
		--it;
		if (_size > count + 1 && count % 2 == 0)
		{
			if (*it > *next)
				std::swap(*it, *next);
		}
		count++;
	}
	for (std::list<int>::iterator it = _lstInt.begin(); it != _lstInt.end(); it++)
	{
		std::list<int>::iterator next;
		next = ++it;
		--it;
		if (next != _lstInt.end())
		{
			_lstIntPair.push_back(std::make_pair(*it, *next));
			_lstIntBiggestPerPair.push_back(*next);
			_lstInt.erase(next);
		}
		else
		{
			_lstIntPair.push_back(std::make_pair(*it, *it));
			_lstIntBiggestPerPair.push_back(*it);
			_lstInt.erase(it);
			break ;
		}
	}

	this->mergeSortLst(_lstIntBiggestPerPair, 0, _lstIntBiggestPerPair.size() - 1);

	for (std::list<std::pair<int, int> >::iterator it = _lstIntPair.begin(); it != _lstIntPair.end(); it++)
	{
		if (it->second == *_lstIntBiggestPerPair.begin())
		{
			if (it->second != it->first)
			{
				_lstIntBiggestPerPair.insert(_lstIntBiggestPerPair.begin(), it->first);
				for (std::list<int>::iterator itLstTab = _lstInt.begin(); itLstTab != _lstInt.end(); itLstTab++)
				{
					if (*itLstTab == it->first)
					{
						_lstInt.erase(itLstTab);
						break;
					}
				}
			}
		}
	}
}

void	PmergeMe::mergeSortLst(std::list<int>& _lstIntBiggestPerPair, size_t left, size_t right)
{
	if (left < right) {
		size_t middle = left + (right - left) / 2;
		mergeSortLst(_lstIntBiggestPerPair, left, middle);
		mergeSortLst(_lstIntBiggestPerPair, middle + 1, right);
		mergeLst(_lstIntBiggestPerPair, left, middle, right);
	}
}

void PmergeMe::mergeLst(std::list<int>& _lstIntBiggestPerPair, size_t left, size_t middle, size_t right)
{
	size_t i, j, k;
	size_t n1 = middle - left + 1;
	size_t n2 = right - middle;

	std::list<int> L, R;

	// Remplir les listes L et R avec les éléments de la liste _lstIntBiggestPerPair
	std::list<int>::iterator it = _lstIntBiggestPerPair.begin();
	std::advance(it, left);
	for (i = 0; i < n1; i++) {
		L.push_back(*it);
		std::advance(it, 1);
	}
	it = _lstIntBiggestPerPair.begin();
	std::advance(it, middle + 1);
	for (j = 0; j < n2; j++) {
		R.push_back(*it);
		std::advance(it, 1);
	}

	// Réinitialiser l'itérateur pour parcourir la liste principale
	it = _lstIntBiggestPerPair.begin();
	std::advance(it, left);

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L.front() <= R.front()) {
			*it = L.front();
			L.pop_front();
			i++;
		} else {
			*it = R.front();
			R.pop_front();
			j++;
		}
		std::advance(it, 1);
		k++;
	}

	// Ajouter les éléments restants de L et R à la liste principale
	while (!L.empty()) {
		*it = L.front();
		L.pop_front();
		std::advance(it, 1);
		k++;
	}
	while (!R.empty()) {
		*it = R.front();
		R.pop_front();
		std::advance(it, 1);
		k++;
	}
}

