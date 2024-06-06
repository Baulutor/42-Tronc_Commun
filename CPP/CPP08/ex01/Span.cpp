//
// Created by dbaule on 4/3/24.
//

#include "Span.hpp"

Span::Span() : _n(0)
{

}

Span::Span(unsigned int N) : _n(N)
{

}

Span::Span(Span const &src) : _n(src._n)
{
    *this = src;
}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

Span::~Span()
{

}


void Span::addNumber(int nbr)
{
    if (this->_vec.size() < this->_n)
        this->_vec.push_back(nbr);
    else
        throw std::out_of_range("You are already to the max of number you can put in your vector");
}

int    Span::shortestSpan()
{
    if (this->_vec.size() < 2)
        throw std::length_error("There is less than two numbers, we can't figure out the shortest Span");

    std::vector<int> copyVector = this->_vec;
    std::sort(copyVector.begin(), copyVector.end());

    int shortSpan = copyVector[1] - copyVector[0];
    for (size_t i = 1; i < copyVector.size(); i++)
    {
        int span = copyVector[i] - copyVector[i - 1];
        if (span < shortSpan)
                shortSpan = span;
    }
    return (shortSpan);
}

unsigned int    Span::longestSpan()
{
    if (this->_vec.size() < 2)
        throw std::length_error("There is less than two numbers, we can't figure out the longest Span");

    std::vector<int>::const_iterator it = this->_vec.begin();
    int buf = *it;
    for (it = this->_vec.begin(); it != this->_vec.end(); it++)
    {
        if (buf > *it)
            buf = *it;
    }

    int temp = buf;

    for (it  = this->_vec.begin(); it != this->_vec.end(); ++it)
    {
        if (temp < *it)
            temp = *it;
    }
    return (temp - buf);
}

void    Span::fillVector()
{
    for (unsigned int i = 0; i < this->_n; i++)
        addNumber(i);
}
