//
// Created by dbaule on 2/23/24.
//

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>
# include <fstream>
# include <ostream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

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
