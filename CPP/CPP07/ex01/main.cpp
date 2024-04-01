//
// Created by dbaule on 4/1/24.
//

#include "iter.hpp"


int main (void)
{
    int intArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "int array :" << std::endl;
    ::iter(intArray, 10, printArray);

    const char *stringArray[2] = {"Hello", "World"};
    std::cout << "const char* array :" << std::endl;
    ::iter(stringArray, 2, printArray);

    float   floatArray[5] = {1.25, 15.2, 98.4, 364.111, 7410.56};
    std::cout << "Float array :" << std::endl;
    ::iter(floatArray, 5, printArray);

}
