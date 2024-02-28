//
// Created by dbaule on 2/8/24.
//
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
	std::cout << this->_name << " destructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->_weapon = &newWeapon;
}


void	HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " is empty handed" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}