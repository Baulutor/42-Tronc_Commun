//
// Created by dbaule on 5/1/24.
//


# include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	PmergeMe PmergeVecLst;
	if (PmergeVecLst.parsing(argc, argv) == 1)
		return (1);
	timeval startVec;
	gettimeofday(&startVec, NULL);
	timeval endVec;
	PmergeVecLst.sortBigPairVec();
	gettimeofday(&endVec, NULL);
	std::cout << "Time to process of " << PmergeVecLst.getSize() << " elements with std::vector : " << endVec.tv_usec - startVec.tv_usec << " us"<< std::endl;
	PmergeVecLst.sortBigPairLst();
	return (0);
}