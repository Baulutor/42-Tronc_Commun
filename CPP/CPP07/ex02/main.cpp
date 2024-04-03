//
// Created by dbaule on 4/3/24.
//


#include "Array.hpp"

int main ()
{

    try
    {
        Array<int> test(10);

        std::cout << test.size() << std::endl;
        std::cout << GREEN << test[2] << RESET << std::endl;
        std::cout << GREEN << test[20] <<  RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        Array<float> test(10);

        std::cout << test.size() << std::endl;
        std::cout << GREEN << test[2] << RESET << std::endl;
        std::cout << GREEN << test[20] << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        Array<char> test(10);

        std::cout << test.size() << std::endl;
        std::cout << GREEN << test[2] << RESET << std::endl;
        std::cout << GREEN << test[20] << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        Array<unsigned int> test(10);

        std::cout << test.size() << std::endl;
        std::cout << GREEN << test[2] << RESET << std::endl;
        std::cout << GREEN << test[20] << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try
    {
        Array<int> test;

        std::cout << test.size() << std::endl;
        std::cout << GREEN << test[0] << RESET << std::endl;
        std::cout << GREEN << test[2] << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
}
