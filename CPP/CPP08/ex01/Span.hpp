//
// Created by dbaule on 4/3/24.
//

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <stdexcept>
# include <algorithm>

class Span
{
private :
    unsigned int        _n;
    std::vector<int>    _vec;
    Span();
public :
    // Constructor and Destructor
    Span(unsigned int N);
    Span(Span const &src);
    Span &operator=(Span const &rhs);
    ~Span();

    //METHOD
    void            addNumber(int nbr);
    int             shortestSpan();
    unsigned int    longestSpan();
    void            fillVector();
};


#endif
