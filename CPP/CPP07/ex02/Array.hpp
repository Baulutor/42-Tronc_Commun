//
// Created by dbaule on 4/3/24.
//

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <cctype>
# include <string>

# define RED		"\033[31m"
# define RESET		"\033[0m"
# define GREEN		"\033[32m"


template<typename T>
class Array
{
private:
    unsigned int _size;
    T   *_array;
public:
    Array() : _size(0){this->_array = (new T[_size]);}
    Array(unsigned int size) : _size(size)
    {
        this->_array = (new T[size]);
        for (unsigned int i = 0; i < this->_size; i++)
            this->_array[i] = 0;
    }
    Array(Array &src) : _size(src._size){*this = src;}
    Array *operator=(Array &rhs)
    {
        if (*this != rhs)
        {
            this->_size = rhs._size;
            this->_array = (new T[this->_size]);
            for (unsigned int i = 0; i < this->_size; i++)
                this->_array[i] = 0;
        }
        return (*this);
    };
    ~Array(){delete []this->_array;}


    // METHOD
    unsigned int    size() const{return (this->_size);}

    T    & operator[](unsigned int n)
    {
        if (n >= this->_size)
            throw OutOfBounds();
        return (this->_array[n]);
    }

    class OutOfBounds : public std::exception
    {
    public :
        virtual const char * what() const throw()
        {
            return ("Can't access, out of bound of the array");
        }
    };
};

#endif
