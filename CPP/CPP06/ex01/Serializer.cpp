//
// Created by dbaule on 3/30/24.
//

#include "Serializer.hpp"

// CONSTRUCTOR AND DESTRUCTOR
Serializer::Serializer()
{

}

Serializer::Serializer(Serializer &src)
{
    *this = src;
}

Serializer &Serializer::operator=(Serializer &rhs)
{
    if (this != &rhs)
    {

    }
    return (*this);
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

