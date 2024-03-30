//
// Created by dbaule on 3/30/24.
//

# include "Base.hpp"

int main ()
{

    std::srand(std::time(0));

    Base *idClass = generate();

    std::cout << "Identify by pointer: " << std::endl;
    identify(idClass);

    std::cout << "Identify by reference: " << std::endl;
    identify(*idClass);
    delete(idClass);
}