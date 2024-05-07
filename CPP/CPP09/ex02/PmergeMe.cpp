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
		_vecTab.erase(it + 1);
	}
	this->mergeSort(_vecTabPair, 0, _vecTabPair.size() - 1);
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

	// Maintenant je dois inserer ce qu'il reste !


//	std::cout << "After: ";
//	for (std::vector<std::pair<int, int> >::iterator it = _vecTabPair.begin(); it != _vecTabPair.end(); it++)
//	{
//		std::cout << it->first << " " << it->second << " ";
//	}
//	std::cout << std::endl;
	std::cout << "After: ";
	for (std::vector<int>::iterator it = _vecTabSort.begin(); it != _vecTabSort.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << _vecTabSort.size() << " oklm " <<std::endl;

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
	if (n > 0) {
		jacobsthalSeq.push_back(1);
		for (int i = 2; i < n ; ++i) {
			int currentTerm = jacobsthalSeq[i - 1] + 2 * jacobsthalSeq[i - 2];
			jacobsthalSeq.push_back(currentTerm);
			if (currentTerm >= static_cast<int>(_vecTab.size()))
				break;
		}
	}
	return jacobsthalSeq;
}

//void	PmergeMe::insertJohnson(std::vector<int> jacob)
//{
//	(void)jacob;
//	_vecTab.clear();
//	for(std::vector<std::pair<int, int> >::iterator it = _vecTabPair.begin(); it < _vecTabPair.end(); it++)
//		_vecTab.push_back(it->first);
//	for (std::vector<int>::iterator it = _vecTab.begin(); it < _vecTab.end(); it++)
//	{
//		int left = 0;
//		int right = _vecTabSort.size() - 1;
//		this->insert(it, left, right);
//	}
//}

void	PmergeMe::insertJohnson(std::vector<int> jacob)
{
	_vecTab.clear();
	for(std::vector<std::pair<int, int> >::iterator it = _vecTabPair.begin(); it < _vecTabPair.end(); it++)
		_vecTab.push_back(it->first);
	for (size_t i = 0; i < jacob.size(); i++)
	{
		int left = 0;
//		std::cout << jacob.size() << " la taille de jacob ! ce qui equivaut a: " << jacob[jacob.size() - 1] << " et la taille de mon bail: "<< _vecTab.size() << std::endl;
		if (static_cast<int>(_vecTab.size()) > jacob[i] || i == 0)
		{
			int right = _vecTabSort.size();
//			std::cout << jacob[i] << " " << _vecTab.size()<< " INFAME  ";
			std::vector<int>::iterator itJac = _vecTab.begin();
			std::advance(itJac, jacob[i]);
			this->insert(itJac, left, right);
//			std::cout << "OKOKOK: " << *itJac << std::endl;

			if (i != 0)
			{
				std::vector<int>::iterator iter = _vecTab.begin();
				std::advance(iter, jacob[i - 1]);
//				std::cout << "Valeur de iter " << *iter << std::endl;
				for (std::vector<int>::iterator it = iter; *it != *itJac; it++)
				{
					int right = _vecTabSort.size();
					this->insert(it, left, right);
//					std::cout << *it << " tgtgtg " << *itJac << std::endl;
				}
			}
		}
		else if (static_cast<int>(_vecTab.size()) <= jacob[i])
		{

//			std::cout << "OKOKKOK   " << "jacob[ i - 1] " << jacob[i - 1]  << " jacob[i]: " << jacob[i] << " vecTab.size() " << _vecTab.size() << std::endl;
			for (size_t ite = jacob[i - 1]; ite < _vecTab.size(); ite++)
			{
				int right = _vecTabSort.size();
				std::vector<int>::iterator it = _vecTab.begin();
				std::advance(it, ite);
//				std::cout << "?????????: " << *it << std::endl;
				this->insert(it, left, right);
			}
		}
	}
}

//void	PmergeMe::insert(std::vector<int>::iterator it, int left, int right)
//{
//	int mid = (right + left) / 2;
//	if ((*it > _vecTabSort[mid] && *it < _vecTabSort[mid + 1]) ||  mid == 0)
//	{
//		std::vector<int>::iterator pos = _vecTabSort.begin() + mid;
//		if (mid == 0)
//		{
//			if (*it > _vecTabSort[mid])
//			{
//				_vecTabSort.insert(pos + 1, *it);
//				return ;
//			}
//			else
//			{
//				_vecTabSort.insert(pos, *it);
//				return ;
//			}
//		}
//		else
//		{
//			_vecTabSort.insert(pos + 1, *it);
//			return ;
//		}
//	}
//	else if (*it < _vecTabSort[mid])
//	{
//		right = mid;
//		this->insert(it, left, right);
//		return ;
//	}
//	else if (*it > _vecTabSort[mid])
//	{
//		left = mid;
//		this->insert(it, left, right);
//		return ;
//	}
//}


void PmergeMe::insert(std::vector<int>::iterator it, int left, int right)
{
	while (left < right)
	{
		int mid = (right + left) / 2; // Utilisation de cette formule pour éviter un débordement en cas de grands nombres
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
//			std::cout << "!!!!!!" << *it << " valeur de _vecTabSort[mid + 1] " << _vecTabSort[mid + 1] << " valeur de left" << left << " et right " << right << std::endl;
			if (*it < _vecTabSort[mid + 1])
			{
				_vecTabSort.insert(_vecTabSort.begin() + mid + 1, *it);
				return;
			}
			left = mid;
		}
		else // Si l'élément est égal au milieu
		{
			return; // Élément déjà présent, ne rien faire
		}
	}
}

void PmergeMe::mergeSort(std::vector<std::pair<int, int> >& _vecTabPair, size_t left, size_t right)
{
	if (left < right) {
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
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			_vecTabPair[k].second = L[i];
			i++;
		} else {
			_vecTabPair[k].second = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		_vecTabPair[k].second = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		_vecTabPair[k].second = R[j];
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

