//
// Created by dbaule on 3/29/24.
//

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cctype>
# include <string>
# include <iostream>
# include <cstdlib>
# include <sstream>
# include <climits>
#include <cfloat>

# define RED		"\033[31m"
# define RESET		"\033[0m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define YELLOW		"\033[33m"


class ScalarConverter {
private :
    // CHECKER
    bool        checkChar(std::string   const str);
    bool        checkInt(std::string   const str);
    bool        checkFloat(std::string   const str);
    bool        checkDouble(std::string   const str);
    // CONVERTOR
    void        convertChar(char const str);
    void        convertInt(std::string const str);
    void        convertFloat(std::string const str);
    void        convertDouble(std::string const str);
    // PRINTER
    void        printChar(char const c);
    void        printInt(long double const value);
    void        printFloat(long double const value);
    void        printDouble(long double const value);
    //EXCEPT
    bool        checkExcept(std::string const str);
public :
    // CONSTRUCTOR AND DESTRUCTOR
    ScalarConverter();
    ScalarConverter(ScalarConverter &src);
    ScalarConverter &operator=(ScalarConverter &rhs);
    ~ScalarConverter();

    // METHOD
    void Convert(std::string const str);
};


#endif //SCALARCONVERTER_HPP
