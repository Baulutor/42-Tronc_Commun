//
// Created by dbaule on 4/1/24.
//

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

template <typename T>
void    iter(T *p, int lengh, void func(const T& compt))
{
    for (int i = 0; i < lengh; i++)
        func(p[i]);
}

template <typename T>
void    printArray(T const array)
{
    std::cout << array << std::endl;
}



#endif //ITER_HPP
