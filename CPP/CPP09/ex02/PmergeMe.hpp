//
// Created by dbaule on 5/1/24.
//

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <climits>
# include <vector>
# include <stdlib.h>
# include <algorithm>
# include <utility>
# include <iterator>
# include <sys/time.h>

class PmergeMe
{
private:
	size_t								_size;

	// Vector data
	std::vector<int>					_vecTab;
	std::vector<int>					_vecTabSort;
	std::vector<std::pair<int, int> > 	_vecTabPair;

	// List data
	std::list<int>						_lstInt;
	std::list<int>						_lstIntBiggestPerPair;
	std::list<std::pair<int, int> > 	_lstIntPair;

public:
	// Constructor Destructor
	PmergeMe();
	PmergeMe(PmergeMe &src);
	PmergeMe &operator=(PmergeMe &rhs);
	~PmergeMe();

	// Getter
	size_t				getSize();

	// Method
	bool				parsing(int argc, char **argv);
	bool				pushVecList(std::string buf);

	// Method for container vector
	void				sortBigPairVec();
	void				mergeSort(std::vector<std::pair<int, int> >& _vecTabBiggestPerPair, size_t left, size_t right);
	void				merge(std::vector<std::pair<int, int> > & _vecTabBiggestPerPair, size_t left, size_t middle, size_t right);
	void				sortJacob();
	std::vector<int>	jacobsthal(int n);
	void				insert(std::vector<int>::iterator it, int left, int right);
	void				insertJohnson(std::vector<int> jacob);
//	int 				insert(int it, int left, int right);


	// Method for container list
	void				sortBigPairLst();
	void				mergeSortLst(std::list<int>& _lstIntBiggestPerPair, size_t left, size_t right);
	void				mergeLst(std::list<int>& _lstIntBiggestPerPair, size_t left, size_t middle, size_t right);

};


#endif