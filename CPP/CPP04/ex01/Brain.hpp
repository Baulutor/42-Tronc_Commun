//
// Created by dbaule on 2/23/24.
//

#ifndef BRAIN_HPP
# define BRAIN_HPP


# include <iostream>
# include <fstream>
# include <ostream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

class Brain
{
protected:
	string _ideas[100];
public:
	Brain();
	Brain & operator=(Brain &rhs);
	Brain(Brain &src);
	~Brain();
};


#endif
