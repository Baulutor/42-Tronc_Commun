#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <cctype>
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private :
		std::string	_name;
		Weapon	&_weapon;
	public :
	// CONSTRUCTOR DESTRUCTOR
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
	//METHOD
		void	attack();
};

#endif