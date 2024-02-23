//
// Created by dbaule on 2/21/24.
//

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

public:
	// CONSTRUCTOR AND DESTRUCTOR
	Dog();
	Dog(Dog & src);
	Dog & operator=(Dog & rhs);
	~Dog();

	// METHOD
	void makeSound() const;
};



#endif
