//
// Created by dbaule on 3/30/24.
//

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::Base()
{

}

Base::~Base()
{

}

Base *generate()
{
    int randNb = std::rand() % 3;

    if (randNb == 0)
        return new A();
    else if (randNb == 1)
        return new B;
    else
        return new C;
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
}

void    identify(Base &p)
{
    Base check;

    if (A* ptrA = dynamic_cast<A*>(&p))
    {
        std::cout << "A" << std::endl;
        (void)ptrA;
    }
    else if (B* ptrB = dynamic_cast<B*>(&p))
    {
        std::cout << "B" << std::endl;
        (void)ptrB;
    }
    else if (C* ptrC = dynamic_cast<C*>(&p))
    {
        std::cout << "C" << std::endl;
        (void)ptrC;
    }
}