//
// Created by dbaule on 3/1/24.
//

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <fstream>
# include <ostream>

# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"

class Brain {
private:
	std::string _ideas[100];
public:
	//CONSTRUCTOR AND DESTRUCTOR
	Brain();
	Brain(std::string oneIdea);
	Brain(Brain & rhs);
	~Brain();
};


#endif
