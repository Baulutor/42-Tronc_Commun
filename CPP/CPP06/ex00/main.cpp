//
// Created by dbaule on 3/29/24.
//

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <ctime>
std::string randomColor();

int main (int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "Put one parameter please !" << std::endl, 1);
    std::srand(std::time(0));

    std::string color = randomColor();


    ScalarConverter test;
    std::cout << color;
    test.Convert(argv[1]);
    std::cout << RESET;

}

std::string randomColor()
{
    int randColor = std::rand() % 6;

    std::string color[6] = {RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW};

    return color[randColor];
}