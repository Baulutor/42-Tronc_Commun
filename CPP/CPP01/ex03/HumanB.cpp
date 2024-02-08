//
// Created by dbaule on 2/8/24.
//
#include "HumanB.hpp"

HumanB::HumanB(string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
	cout << this->_name << " destructor called" << endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->_weapon = &newWeapon;
}


void	HumanB::attack()
{
	if (this->_weapon == NULL)
		cout << this->_name << " is empty handed" << endl;
	else
		cout << this->_name << " attacks with their " << this->_weapon->getType() << endl;
}