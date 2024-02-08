//
// Created by dbaule on 2/8/24.
//

#include "HumanA.hpp"
#include "Weapon.hpp"

Weapon::Weapon(string type) : _type(type)
{

}

Weapon::~Weapon()
{

}

const string	&Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(string type)
{
	this->_type = type;
}
