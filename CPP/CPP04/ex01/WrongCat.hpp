//
// Created by dbaule on 2/23/24.
//

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat  : public WrongAnimal
{
public :
	WrongCat();
	WrongCat(WrongCat & src);
	WrongCat & operator=(WrongCat & rhs);
	~WrongCat();

	// METHOD
	void makeSound() const;
};


#endif
