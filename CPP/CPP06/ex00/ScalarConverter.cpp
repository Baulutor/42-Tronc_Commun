//
// Created by dbaule on 3/29/24.
//

#include "ScalarConverter.hpp"

/* CONSTRUCTOR AND DESTRUCTOR */
ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs)
{
    if (this != &rhs)
    {

    }
    return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

// METHOD
void    ScalarConverter::Convert(std::string const str)
{

    if (str.length() < 1)
    {
        std::cout << "Please give at least one character, there is nothing in it" << std::endl;
        return ;
    }
    if (checkExcept(str))
        return ;
    bool     checkType[3] = { checkInt(str), checkFloat(str), checkDouble(str)};
    void (*convertType[3])(std::string const) = {&convertInt, &convertFloat, &convertDouble};
    for (int i = 0; i < 3; i++)
    {
        if (checkType[i])
        {
            (*convertType[i])(str);
            return ;
        }
    }
    if (str.length() == 1)
        convertChar(str[0]);
    else
        std::cout << "please put digits or one character, but one a string" << std::endl;
}
