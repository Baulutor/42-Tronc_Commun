//
// Created by dbaule on 2/21/24.
//

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
//	Brain *_test;
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
