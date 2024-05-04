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

class PmergeMe
{
private:
	std::vector<int>	_vecTab;
	std::vector<int>	_vecTabBiggestPerPair;
	std::vector<std::pair<int, int> > _vecTabPair;
	size_t				_size;

public:
	// Constructor Destructor
	PmergeMe();
	PmergeMe(PmergeMe &src);
	PmergeMe &operator=(PmergeMe &rhs);
	~PmergeMe();

	// Method
	bool	pushVec(std::string buf);
	bool	parsing(int argc, char **argv);
	void	sortBigPair();
	void	mergeSort(std::vector<int>& _vecTabBiggestPerPair, size_t left, size_t right);
	void	merge(std::vector<int>& _vecTabBiggestPerPair, size_t left, size_t middle, size_t right);
	void	sortJacob();
	int		jacobsthal(int n);
};


#endif
