//
// Created by dbaule on 3/30/24.
//


#include "Serializer.hpp"

/* uintptr_t : it's used for address storage,
 * it's considered very reliable with lots of storage space (so good for casting)*/

int main ()
{
    Data    ogData;

    ogData.a = 'c';
    ogData.b = 15;
    ogData.c = 30.256f;
    ogData.d = 1.25897;


    Serializer serial;

    std::cout << BLUE << "Address of the original: " << &ogData << std::endl;
    std::cout << "Data.a: " << ogData.a << std::endl;
    std::cout << "Data.b: " << ogData.b << std::endl;
    std::cout << "Data.c: " << ogData.c << std::endl;
    std::cout << "Data.d: " << ogData.d << std::endl;

    uintptr_t execSerial = serial.serialize(&ogData);
    std::cout << RED << "Now the address as been casted in uintptr_t due to serialize: " << execSerial << std::endl;
    Data *newData = serial.deserialize(execSerial);
    std::cout << GREEN << "The new address of Data: " << newData << std::endl;
    std::cout << "newData.a: " << newData->a << std::endl;
    std::cout << "newData.b: " << newData->b << std::endl;
    std::cout << "newData.c: " << newData->c << std::endl;
    std::cout << "newData.d: " << newData->d << RESET << std::endl;




    return (0);
}