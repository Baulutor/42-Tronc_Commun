//
// Created by dbaule on 4/17/24.
//

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <vector>


template <typename T>
class MutantStack : public std::stack<T>
{
public :
    MutantStack() {}
    MutantStack(MutantStack &src) {*this = src;}
    MutantStack &operator=(MutantStack &rhs)
    {
        if (*this != rhs)
            this->c = rhs.c;
        return (*this);
    }
    ~MutantStack(){}
    typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type ::const_iterator const_iterator;

	void clearC(){(this->c.clear());}

    iterator begin(){return  this->c.begin();}
    iterator end(){return  this->c.end();}

	const_iterator begin() const {return this->c.begin();}
	const_iterator end() const {return this->c.end();}



};

#endif
