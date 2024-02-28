#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cctype>
# include <string>
# include <iostream>

# define NBR_HORDE 5

class Zombie
{
	private :
		std::string _name;
	public :
	// CONSTRUCTOR DESTRUCTOR
		Zombie(void);
		~Zombie(void);
	// SETTER AND GETTER
		void	setName(std::string str);
	//METHOD
		void	announce()const;
};
	Zombie *zombieHorde(int n, std::string name);

#endif