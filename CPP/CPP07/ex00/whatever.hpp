//
// Created by dbaule on 4/1/24.
//

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &x, T &y)
{
    T tmp;
    tmp = y;
    y = x;
    x = tmp;
}

template <typename T>
T const &min(T const &x, T const &y)
{
    return (x < y ? x : y);
}

template <typename T>
T  const &max(T const &x, T const &y)
{
    return (x > y ? x : y);
}

#endif
