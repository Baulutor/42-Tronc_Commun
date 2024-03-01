//
// Created by dbaule on 2/21/24.
//

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"


class Cat : public Animal
{
private:
	Brain *_catBrain;
public:
	// CONSTRUCTOR AND DESTRUCTOR
	Cat();
	Cat(std::string name);
	Cat(Cat & src);
	~Cat();

	// METHOD
	void makeSound() const;
};


#endif
