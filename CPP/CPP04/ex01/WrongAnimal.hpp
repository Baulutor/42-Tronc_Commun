//
// Created by dbaule on 2/23/24.
//

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>
# include <fstream>
# include <ostream>

class WrongAnimal {
protected :
	std::string	_type;
public :
	// CONSTRUCTOR AND DESTRUCTOR
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal & src);
	~WrongAnimal();

	//GETTER AND SETTER
	std::string	getType() const;
	void	makeSound() const;
};


#endif
