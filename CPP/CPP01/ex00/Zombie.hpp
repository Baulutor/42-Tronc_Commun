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
		Zombie(string name);
		~Zombie(void);

	//METHOD
		void	announce()const;
};

		Zombie	*newZombie(string name);
		void	randomChump(string name);
#endif