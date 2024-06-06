//
// Created by dbaule on 4/3/24.
//


#include "easyfind.hpp"


int main ()
{

    std::vector<int> Vector;
	std::list<int> Lst;

    int     intValue = 1;
    int     researchValue = 4;

    Vector.push_back(intValue);
    Vector.push_back(2);
    Vector.push_back(9);
    if (easyfind(Vector, researchValue) == 1)
        std::cout << GREEN << "there is " << researchValue << " in this Vector" << RESET << std::endl;
    else
	{
        std::cout << RED << "there is no " << researchValue << " in this Vector" << RESET << std::endl;
	}
	Lst.push_back(intValue);
	Lst.push_back(4);
	Lst.push_back(40);
	if (easyfind(Lst, researchValue) == 1)
		std::cout << std::endl << GREEN << "there is " << researchValue << " in this Vector" << RESET << std::endl;
	else
		std::cout << RED << "there is no " << researchValue << " in this Vector" << RESET << std::endl;
}
