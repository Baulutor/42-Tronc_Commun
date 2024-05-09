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

std::list<int> &PmergeMe::getSortedLst()
{
	return (_lstIntSort);
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
	swapPairVec();
	mergeSort(_vecTabPair, 0, _vecTabPair.size() - 1);
	_vecTabSort.push_back(_vecTabPair[0].first);
	bool flag = 0;
	for (std::vector<std::pair<int,int> >::iterator it = _vecTabPair.begin(); it < _vecTabPair.end(); it++)
	{
		_vecTabSort.push_back(it->second);
		if (flag == 0)
		{
			_vecTabPair.erase(it);
			it--;
			flag = 1;
		}
	}
	sortJacob();
	std::cout << "After: ";
	for (std::vector<int>::iterator it = _vecTabSort.begin(); it != _vecTabSort.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << _vecTabSort.size() << " oklm " <<std::endl;
}

void	PmergeMe::swapPairVec()
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
		_vecTab.erase(it + 1);
	}
}

void	PmergeMe::sortJacob()
{
	std::vector<int> jacob = this->jacobsthal(_vecTab.size() - 1);
	insertJohnson(jacob);
}

std::vector<int> PmergeMe::jacobsthal(int n)
{
	std::vector<int> jacobsthalSeq;
	jacobsthalSeq.push_back(0);
	if (n > 0)
	{
		jacobsthalSeq.push_back(1);
		for (int i = 2; i < n ; ++i)
		{
			int currentTerm = jacobsthalSeq[i - 1] + 2 * jacobsthalSeq[i - 2];
			jacobsthalSeq.push_back(currentTerm);
			if (currentTerm >= static_cast<int>(_vecTab.size()))
				break;
		}
	}
	return jacobsthalSeq;
}

void	PmergeMe::insertJohnson(std::vector<int> jacob)
{
	_vecTab.clear();
	for(std::vector<std::pair<int, int> >::iterator it = _vecTabPair.begin(); it < _vecTabPair.end(); it++)
		_vecTab.push_back(it->first);
	for (size_t i = 0; i < jacob.size(); i++)
	{
		int left = 0;
		if (static_cast<int>(_vecTab.size()) > jacob[i] || i == 0)
		{
			int right = _vecTabSort.size();
			std::vector<int>::iterator itJac = _vecTab.begin();
			std::advance(itJac, jacob[i]);
			this->insert(itJac, left, right);

			if (i != 0)
			{
				std::vector<int>::iterator iter = _vecTab.begin();
				std::advance(iter, jacob[i - 1]);
				for (std::vector<int>::iterator it = iter; *it != *itJac; it++)
				{
					int right = _vecTabSort.size();
					this->insert(it, left, right);
				}
				// Only in the case of 8 or 9 elements, because two time 1 value for Jacobsthal
				if (jacob[i] == jacob[i - 1])
				{
					for (size_t ite = (jacob[i]) + 1; ite < _vecTab.size(); ite++)
					{
						int right = _vecTabSort.size();
						std::vector<int>::iterator it = _vecTab.begin();
						std::advance(it, ite);
						this->insert(it, left, right);
					}
				}
			}
		}
		else if (static_cast<int>(_vecTab.size()) <= jacob[i])
		{
			for (size_t ite = (jacob[i - 1]) + 1; ite < _vecTab.size(); ite++)
			{
				int right = _vecTabSort.size();
				std::vector<int>::iterator it = _vecTab.begin();
				std::advance(it, ite);
				this->insert(it, left, right);
			}
		}
	}
}



void PmergeMe::insert(std::vector<int>::iterator it, int left, int right)
{
	while (left < right)
	{
		int mid = (right + left) / 2;
		if (*it < _vecTabSort[mid])
		{
			if (mid == 0 || *it > _vecTabSort[mid - 1])
			{
				_vecTabSort.insert(_vecTabSort.begin() + mid, *it);
				return;
			}
			right = mid;
		}
		else if (*it > _vecTabSort[mid])
		{
			if (*it < _vecTabSort[mid + 1])
			{
				_vecTabSort.insert(_vecTabSort.begin() + mid + 1, *it);
				return;
			}
			left = mid;
		}
		else
			return;
	}
}

void PmergeMe::mergeSort(std::vector<std::pair<int, int> >& _vecTabPair, size_t left, size_t right)
{
	if (left < right)
	{
		size_t middle = left + (right - left) / 2;

		mergeSort(_vecTabPair, left, middle);
		mergeSort(_vecTabPair, middle + 1, right);
		merge(_vecTabPair, left, middle, right);
	}
}


void PmergeMe::merge(std::vector<std::pair<int, int> >& _vecTabPair, size_t left, size_t middle, size_t right)
{
	size_t i, j, k;
	size_t n1 = middle - left + 1;
	size_t n2 = right - middle;

	std::vector<int> L(n1), R(n2);

	for (i = 0; i < n1; i++)
		L[i] = _vecTabPair[left + i].second;
	for (j = 0; j < n2; j++)
		R[j] = _vecTabPair[middle + 1 + j].second;
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			_vecTabPair[k].second = L[i];
			i++;
		}
		else
		{
			_vecTabPair[k].second = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		_vecTabPair[k].second = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		_vecTabPair[k].second = R[j];
		j++;
		k++;
	}
}

// Method list

void	PmergeMe::sortBigPairLst()
{
	swapPairLst();

	std::list<int> bigNumbers;
	for (std::list<std::pair<int, int> >::iterator it = _lstIntPair.begin(); it != _lstIntPair.end(); it++)
		bigNumbers.push_back(it->second);
	this->mergeSortLst(bigNumbers, 0, bigNumbers.size() - 1);
	size_t i = 0;
	for (std::list<int>::iterator it = bigNumbers.begin(); it != bigNumbers.end(); it++)
	{
		for (std::list<std::pair<int, int> >::iterator ite = _lstIntPair.begin(); ite != _lstIntPair.end(); ite++)
		{
			if (*it == ite->second)
			{
				std::list<std::pair<int, int> >::iterator buf = _lstIntPair.begin();
				std::advance(buf, i);
				std::swap(*ite, *buf);
				break;
			}
		}
		i++;
	}
	int flag = 0;
	for (std::list<std::pair<int, int> >::iterator it = _lstIntPair.begin(); flag == 1 || it != _lstIntPair.end(); it++)
	{
		if (flag == 1)
		{
			flag = 2;
			it--;
		}
		_lstIntSort.push_back(it->second);
		if (flag == 0)
		{
			_lstIntSort.push_front(it->first);
			_lstIntPair.erase(it);
			it = _lstIntPair.begin();
			flag = 1;
		}
	}
	_lstInt.clear();
	for (std::list<std::pair<int, int> >::iterator it = _lstIntPair.begin(); it != _lstIntPair.end(); it++)
	{
		if (it->first != it->second)
			_lstInt.push_back(it->first);
	}
	sortJacobLst();
}

void	PmergeMe::swapPairLst()
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
			_lstInt.erase(next);
		}
		else
		{
			_lstIntPair.push_back(std::make_pair(*it, *it));
			_lstInt.erase(it);
			break ;
		}
	}
}


void	PmergeMe::mergeSortLst(std::list<int> &bigNumbers, size_t left, size_t right)
{

	if (left < right)
	{
		size_t middle = (left + right) / 2;

		mergeSortLst(bigNumbers, left, middle);
		mergeSortLst(bigNumbers, middle + 1, right);
		mergeLst(bigNumbers, left, middle, right);
	}
}

void 	PmergeMe::mergeLst(std::list<int> &lst, size_t left, size_t mid, size_t right)
{
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;

	std::list<int> L;
	std::list<int> R;

	std::list<int>::iterator it = lst.begin();
	std::advance(it, left);
	for (size_t i = 0; i < n1; ++i)
	{
		L.push_back(*it);
		++it;
	}

	it = lst.begin();
	std::advance(it, mid + 1);
	for (size_t j = 0; j < n2; ++j)
	{
		R.push_back(*it);
		++it;
	}

	it = lst.begin();
	std::advance(it, left);
	size_t i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		if (L.front() <= R.front())
		{
			*it = L.front();
			L.pop_front();
			++i;
		} else {
			*it = R.front();
			R.pop_front();
			++j;
		}
		++it;
	}

	while (i < n1)
	{
		*it = L.front();
		L.pop_front();
		++i;
		++it;
	}

	while (j < n2)
	{
		*it = R.front();
		R.pop_front();
		++j;
		++it;
	}
}

void	PmergeMe::sortJacobLst()
{
	std::list<int> jacob = this->jacobsthalLst(_lstInt.size());
	insertJohnsonLst(jacob);
}

std::list<int> PmergeMe::jacobsthalLst(int n)
{
	std::list<int> jacobsthalSeq;
	jacobsthalSeq.push_back(0);
	if (n > 0)
	{
		jacobsthalSeq.push_back(1);
		for (int i = 2; i < n ; ++i)
		{
			std::list<int>::iterator prev = jacobsthalSeq.begin();
			std::list<int>::iterator twoPrev = jacobsthalSeq.begin();
			std::advance(prev, i - 1);
			std::advance(twoPrev, i - 2);
			int currentTerm = *prev + 2 * *twoPrev;
			jacobsthalSeq.push_back(currentTerm);
			if (currentTerm >= static_cast<int>(_lstInt.size()))
				break;
		}
	}
	return (jacobsthalSeq);
}

void	PmergeMe::insertJohnsonLst(std::list<int> jacob)
{
	size_t	jacobIter = 0;
	for (std::list<int>::iterator i = jacob.begin(); i != jacob.end(); i++)
	{
		int left = 0;
		std::list<int>::iterator prevJacob = jacob.begin();
		if (i != jacob.begin())
			std::advance(prevJacob, jacobIter - 1);
		if (static_cast<int>(_vecTab.size()) > *i || i == jacob.begin())
		{
			int right = _lstIntSort.size();
			std::list<int>::iterator itJac = _lstInt.begin();
			std::advance(itJac, *i);
			this->insertLst(itJac, left, right);
			if (*i != 0)
			{
				std::list<int>::iterator iter = _lstInt.begin();
				std::advance(iter, *prevJacob + 1);
				for (std::list<int>::iterator it = iter; *it != *itJac; it++)
				{
					int right = _lstIntSort.size();
					this->insertLst(it, left, right);
				}
			}
		}
		else if (static_cast<int>(_vecTab.size()) <= *i)
		{
			for (size_t ite = *prevJacob + 1; ite != _lstInt.size(); ite++)
			{
				int right = _lstIntSort.size();
				std::list<int>::iterator it = _lstInt.begin();
				std::advance(it, ite);
				this->insertLst(it, left, right);
			}
		}
		jacobIter++;
	}
}

void PmergeMe::insertLst(std::list<int>::iterator it, int left, int right)
{
	while (left < right)
	{
		std::list<int>::iterator ite = _lstIntSort.begin();
		int mid = (right + left) / 2;
		std::advance(ite, mid);
		if (*it < *ite)
		{
			std::list<int>::iterator prev = --ite;
			++ite;
			if (mid == 0 || *it > *prev)
			{
				_lstIntSort.insert(ite, *it);
				return;
			}
			right = mid;
		}
		else if (*it > *ite)
		{
			std::list<int>::iterator next = ++ite;
			ite--;
			if (*it < *next)
			{
				_lstIntSort.insert(next, *it);
				return;
			}
			left = mid;
		}
		else
			return;
	}
}


void	PmergeMe::printList()
{
	std::cout << "List sorted : ";
	for (std::list<int>::iterator it = _lstIntSort.begin(); it != _lstIntSort.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
