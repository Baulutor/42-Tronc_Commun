#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <cctype>
#include <string>
#include <iostream>

class Zombie
{
	private :
		std::string _name;
	public :
	// CONSTRUCTOR DESTRUCTOR
		Zombie(std::string name);
		~Zombie(void);

	//METHOD
		void	announce()const;
};

		Zombie	*newZombie(std::string name);
		void	randomChump(std::string name);
#endif