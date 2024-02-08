#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cctype>
# include <string>
# include <iostream>

# define NBR_HORDE 5

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
	// SETTER AND GETTER
		void	setName(string str);
	//METHOD
		void	announce()const;
};
	Zombie *zombieHorde(int n, string name);

#endif