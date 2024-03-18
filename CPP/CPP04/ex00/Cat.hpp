//
// Created by dbaule on 2/21/24.
//

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
public:
	// CONSTRUCTOR AND DESTRUCTOR
	Cat();
	Cat(Cat & src);
	Cat & operator=(Cat & rhs);
	~Cat();

	// METHOD
	void makeSound() const;
};


#endif
