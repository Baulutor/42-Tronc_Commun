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
	string	_type;
public :
	// CONSTRUCTOR AND DESTRUCTOR
	WrongAnimal();
	WrongAnimal(string type);
	WrongAnimal(WrongAnimal & src);
	WrongAnimal & operator=(WrongAnimal & rhs);
	~WrongAnimal();

	//GETTER AND SETTER
	string	getType() const;
	void	makeSound() const;
};


#endif
