//
// Created by dbaule on 4/3/24.
//


#include "easyfind.hpp"


int main ()
{

    std::vector<int> Vector;

    int     intValue = 1;
    int     researchValue = 5;

    Vector.push_back(intValue);
    Vector.push_back(2);
    Vector.push_back(5);
    if (easyfind(Vector, researchValue) == 1)
        std::cout << GREEN << "there is " << researchValue << " in this Vector" << RESET << std::endl;
    else
        std::cout << RED << "there is no " << researchValue << " in this Vector" << RESET << std::endl;

}
