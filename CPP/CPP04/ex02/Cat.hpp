//
// Created by dbaule on 2/21/24.
//

#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"


class Cat : public AAnimal
{
private:
	Brain *_catBrain;
public:
	// CONSTRUCTOR AND DESTRUCTOR
	Cat();
	Cat(std::string name);
	Cat & operator=(Cat &rhs);
	Cat(Cat & src);
	~Cat();

	// METHOD
	void 		makeSound() const;
	std::string getIdea() const;
	void		setIdea(std::string newIdea);
};


#endif
