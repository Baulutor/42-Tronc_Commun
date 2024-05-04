//
// Created by dbaule on 5/1/24.
//


# include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	PmergeMe PmergeVec;
	if (PmergeVec.parsing(argc, argv) == 1)
		return (1);
	PmergeVec.sortBigPair();
	return (0);
}