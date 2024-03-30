//
// Created by dbaule on 3/29/24.
//

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "ForConvert.h"

class ScalarConverter {
private :

public :
    // CONSTRUCTOR AND DESTRUCTOR
    ScalarConverter();
    ScalarConverter(ScalarConverter &src);
    ScalarConverter &operator=(ScalarConverter &rhs);
    ~ScalarConverter();

    // METHOD
    static void Convert(std::string const str);
};

#endif //SCALARCONVERTER_HPP
