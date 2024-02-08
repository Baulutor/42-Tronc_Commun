//
// Created by dbaule on 2/8/24.
//

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
	cout << this->_name << " destructor called " << endl;
}

void	HumanA::attack()
{
	cout << this->_name << " attacks with their " << this->_weapon.getType() << endl;
}

