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
    int buf = 0;
    long int temp = 1000000000000000;
    for (std::vector<int>::const_iterator test = this->_vec.begin(); test < this->_vec.end(); test++)
    {
        buf = *test;
        for (std::vector<int>::const_iterator it = this->_vec.begin(); it < this->_vec.end(); it++)
        {

            if (buf != *it && *it - buf < temp && *it - buf > 0)
            {
                std::cout << "test : "<< *it - buf << std::endl;
                temp = buf - *it;
            }

        }
    }
    if (temp < 0)
        temp *= -1;
    return (temp);
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
    for (it  = this->_vec.begin(); it != this->_vec.end(); it++)
    {
        if (temp < *it)
            temp = *it;
    }
    return (temp - buf);

    return (0);
}