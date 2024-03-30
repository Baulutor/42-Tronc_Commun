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
    if (this->checkExcept(str))
        return ;
    bool     checkType[3] = { this->checkInt(str), this->checkFloat(str), this->checkDouble(str)};
    void (ScalarConverter::*convertType[3])(std::string const) = {&ScalarConverter::convertInt, &ScalarConverter::convertFloat, &ScalarConverter::convertDouble};
    for (int i = 0; i < 3; i++)
    {
        if (checkType[i])
        {
            (this->*convertType[i])(str);
            return ;
        }
    }
    if (str.length() == 1)
        this->convertChar(str[0]);
}

/* CHECKER OF THE INITIALISE TYPE */

bool    ScalarConverter::checkInt(const std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (i == 0 && (str[0] == '+' || str[0] == '-'))
            i++;
        if (isdigit(str[i]) == 0)
            return false;
    }
    return true;
}

bool    ScalarConverter::checkFloat(const std::string str)
{
    if (str.find_first_of("f") != str.npos && str.find_first_of(".") != str.npos)
        return true;
    return false;
}

bool    ScalarConverter::checkDouble(const std::string str)
{
    if (str.find_first_of(".") == str.npos)
        return false;
    return true;
}

// CONVERTOR

void    ScalarConverter::convertChar(const char c)
{
//     std::cout << "in Char converter" << std::endl;
    this->printChar(c);
    long double buf = static_cast<long double>(c);
    this->printInt(buf);
    this->printFloat(buf);
    this->printDouble(buf);
}

void ScalarConverter::convertInt(const std::string str)
{
    long buf = atof(str.c_str());
    char c = static_cast<char>(buf);

//    std::cout << "In Int converter" << std::endl;
    this->printChar(c);
    if (buf >= static_cast<int>(INT_MIN) && buf <= static_cast<int>(INT_MAX))
        std::cout << "int: " << static_cast<int>(buf) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (buf >= static_cast<float>(FLT_MAX * -1) && buf <= static_cast<float>(FLT_MAX))
        std::cout << "float: " << static_cast<float>(buf) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    if (buf >= static_cast<double>(DBL_MAX * -1) && buf <= static_cast<double>(DBL_MAX))
        std::cout << "double: " << static_cast<double>(buf) << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void    ScalarConverter::convertFloat(const std::string str)
{
//    std::cout << "in Float converter" << std::endl;
    float buf = atof(str.c_str());
    char c = static_cast<char>(buf);
    this->printChar(c);
    this->printInt(static_cast<long double>(buf));
    this->printFloat(static_cast<long double>(buf));
    this->printDouble(static_cast<long double>(buf));

}

void    ScalarConverter::convertDouble(const std::string str)
{
//    std::cout << "in Double converter" << std::endl;
    double buf = atof(str.c_str());
    char c = static_cast<char>(buf);
    this->printChar(c);
    this->printInt(static_cast<long double>(buf));
    this->printFloat(static_cast<long double>(buf));
    this->printDouble(static_cast<long double>(buf));
}


/* PRINTER */



void    ScalarConverter::printChar(char const c)
{
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void    ScalarConverter::printInt(const long double value)
{
    if (value >= static_cast<int>(INT_MIN) && value <= static_cast<int>(INT_MAX))
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void    ScalarConverter::printFloat(const long double value)
{
    if (value >= static_cast<float>(FLT_MAX * -1) && value <= static_cast<float>(FLT_MAX))
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
}

void    ScalarConverter::printDouble(const long double value)
{
    if (value >= static_cast<double>(DBL_MAX * -1) && value <= static_cast<double>(DBL_MAX))
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

// EXCEPTION

bool     ScalarConverter::checkExcept(std::string const str)
{
    if (str == "+inf"  || str == "+inff")
    {
        std::cout << "Char convert : impossible" << std::endl;
        std::cout << "Int convert : impossible" << std::endl;
        std::cout << "Float convert : +inff" << std::endl;
        std::cout << "Double convert : +inf" << std::endl;
        return (true);
    }
    if (str == "-inf" || str == "-inff")
    {
        std::cout << "Char convert : impossible" << std::endl;
        std::cout << "Int convert : impossible" << std::endl;
        std::cout << "Float convert : -inff" << std::endl;
        std::cout << "Double convert : -inf" << std::endl;
        return (true);
    }
    if (str == "nanf" || str == "nan")
    {
        std::cout << "Char convert : impossible" << std::endl;
        std::cout << "Int convert : impossible" << std::endl;
        std::cout << "Float convert : nanf" << std::endl;
        std::cout << "Double convert : nan" << std::endl;
        return (true);
    }
    return (false);
}