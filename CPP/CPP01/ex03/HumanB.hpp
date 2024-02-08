

#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP


# include <cctype>
# include <string>
# include <iostream>
# include "Weapon.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;

class HumanB
{
private :
	string	_name;
	Weapon	*_weapon;
public :
	// CONSTRUCTOR DESTRUCTOR
	HumanB(string name);
	~HumanB(void);

	//SETTER
	void	setWeapon(Weapon &newWeapon);
	//METHOD
	void	attack();
};

#endif
