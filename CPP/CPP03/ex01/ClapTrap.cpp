#include "ClapTrap.hpp"


/* --------------------CONSTRUCTOR AND DESTRUCTOR-------------------- */

ClapTrap::ClapTrap()
{

}

ClapTrap::ClapTrap(string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	cout << "Default constructor of ClapTrap " << BLUE << this->_name << RESET << " called" << endl;
}

ClapTrap::ClapTrap(string name, int hitpoint, int energypoint, unsigned int attdmg) : _name(name), _hitPoint(hitpoint), _energyPoint(energypoint), _attackDamage(attdmg)
{
	cout << "Default constructor of Claptrap " << BLUE << this->_name << RESET << " called" << endl;
}

ClapTrap::ClapTrap(ClapTrap & src)
{
	this->_name = src.getName();
	this->_hitPoint = src.getHitPoint();
	this->_attackDamage = src.getAttackDamage();
	this->_energyPoint = src.getEnergyPoint();
	cout << "Copy constructor of " << BLUE << this->_name << RESET << " called" << endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoint = rhs.getHitPoint();
		this->_attackDamage = rhs.getAttackDamage();
		this->_energyPoint = rhs.getEnergyPoint();
	}
	cout << "Copy assignment operator " << BLUE << this->_name << RESET << " called" << endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	cout << "Destructor of ClapTrap " << BLUE << this->_name << RESET << " called" << endl;
}


/* --------------------GETTER-------------------- */

string	ClapTrap::getName()
{
	return (this->_name);
}

int 	ClapTrap::getHitPoint()
{
	return (this->_hitPoint);
}

int 	ClapTrap::getEnergyPoint()
{
	return (this->_energyPoint);
}

int 	ClapTrap::getAttackDamage()
{
	return (this->_attackDamage);
}

/* --------------------SETTER-------------------- */

void	ClapTrap::setHitPoint(int admg) {
	this->_hitPoint -= admg;
}

void	ClapTrap::setAttackDamage(int newad) {
	this->_attackDamage = newad;
}


void	ClapTrap::setEnergyPoint(int newep) {
	this->_energyPoint -= newep;
}



/* --------------------METHOD-------------------- */

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoint <= 0)
	{
		cout << BLUE << this->_name << RESET << " is already dead, he can't attack" << endl;
		return ;
	}
	if (this->_energyPoint <= 0)
	{
		this->_energyPoint -= 1;
		cout << BLUE << this->_name << RESET << " has no energy left, he can't attack" << endl;
		return ;
	}
	this->_energyPoint -= 1;

	cout << RED << "ClapTrap " << BLUE << this->_name << RED << " attacks " << target << " , causing "<< this->_attackDamage << " points of damage!" << RESET << endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoint <= 0)
	{
		cout  << "Stop it, " << BLUE << this->_name << RESET << " is already dead..." << endl;
		return ;
	}
	cout << BLUE << this->_name << RESET << " had " << this->_hitPoint << " hit point";

	this->_hitPoint -= amount;
	cout << " by taking " << amount << " damage, he has now " << this->_hitPoint << " hitpoint left" << endl;
	if (this->_hitPoint <= 0)
	{
		cout << BLUE << this->_name  << MAGENTA << " is dead" << RESET << endl;
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoint <= 0)
	{
		cout << BLUE << this->_name << RESET << " is already dead, he can't repair himself" << endl;
		return ;
	}

	if (this->_energyPoint <= 0)
	{
		cout << BLUE << this->_name << RESET << " has no energy left, he can't repair himself" << endl;
		return ;
	}
	this->_energyPoint -= 1;
	cout << BLUE << this->_name << GREEN << " repair himself for " << amount << ", he was at " << this->_hitPoint << " hitpoint";
	this->_hitPoint += amount;
	cout << ", now he have " << this->_hitPoint << " hitpoint" << RESET << endl;
}