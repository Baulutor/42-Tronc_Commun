//
// Created by dbaule on 2/21/24.
//

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

private:
	Brain *_dogBrain;

public:
	// CONSTRUCTOR AND DESTRUCTOR
	Dog();
	Dog(std::string name);
	Dog & operator=(Dog &rhs);
	Dog(Dog & src);
	~Dog();

	// METHOD
	void makeSound() const;
};



#endif
