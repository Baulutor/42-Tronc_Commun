

#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP


# include <cctype>
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private :
	std::string	_name;
	Weapon	*_weapon;
public :
	// CONSTRUCTOR DESTRUCTOR
	HumanB(std::string name);
	~HumanB(void);

	//SETTER
	void	setWeapon(Weapon &newWeapon);
	//METHOD
	void	attack();
};

#endif
