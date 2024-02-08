#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <cctype>
# include <string>
# include <iostream>
# include "Weapon.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;

class HumanA
{
	private :
		string	_name;
		Weapon	&_weapon;
	public :
	// CONSTRUCTOR DESTRUCTOR
		HumanA(string name, Weapon &weapon);
		~HumanA(void);
	//METHOD
		void	attack();
};

#endif