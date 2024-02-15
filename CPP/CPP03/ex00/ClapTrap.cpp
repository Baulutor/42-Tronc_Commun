#include "ClapTrap.hpp"


ClapTrap::ClapTrap(string name) : _name(name)
{

}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	this->_name = src._name; // getter setter ??
	this->_hitPoint = src._hitPoint;
	this->_attackDamage = src._attackDamage;
	this->_energyPoint = src._energyPoint;
}

ClapTrap & operator=(ClapTrap & rhs)
{
	if (this != rhs)
	{
		this->_name = rhs._name; // getter setter ??
		this->_hitPoint = rhs._hitPoint;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoint = rhs._energyPoint;
	}
	else
		return (*this*)
}

ClapTrap::~ClapTrap()
{

}

