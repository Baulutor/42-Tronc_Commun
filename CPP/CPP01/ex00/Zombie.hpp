#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <cctype>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

class Zombie
{
	private :
		string _name;
	public :
	// CONSTRUCTOR DESTRUCTOR
		Zombie(void);
		~Zombie(void);
};

#endif