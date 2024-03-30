//
// Created by dbaule on 3/30/24.
//

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>
#include <iostream>

# define RED		"\033[31m"
# define RESET		"\033[0m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"

struct Data {
    char a;
    int b;
    float c;
    double d;
};

class Serializer
{
public :
    Serializer();
    Serializer(Serializer &src);
    Serializer &operator=(Serializer &rhs);
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data *deserialize(uintptr_t raw);

};


#endif
