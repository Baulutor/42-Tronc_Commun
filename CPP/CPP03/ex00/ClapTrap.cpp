#include "ClapTrap.hpp"


/* --------------------CONSTRUCTOR AND DESTRUCTOR-------------------- */


ClapTrap::ClapTrap() : _name("Prototype"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Default constructor of " << BLUE << "Prototype" << RESET << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Default constructor of " << BLUE << this->_name << RESET << " called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap & src)
{
	std::cout << "Copy constructor of " << BLUE << this->_name << RESET << " called" << std::endl;
	this->_name = src.getName();
	this->_hitPoint = src.getHitPoint();
	this->_attackDamage = src.getAttackDamage();
	this->_energyPoint = src.getEnergyPoint();
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
	std::cout << "Copy assignment operator " << BLUE << this->_name << RESET << " called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of " << BLUE << this->_name << RESET << " called" << std::endl;
}


/* --------------------GETTER-------------------- */

std::string	ClapTrap::getName()
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
		std::cout << BLUE << this->_name << RESET << " is already dead, he can't attack" << std::endl;
		return ;
	}
	if (this->_energyPoint <= 0)
	{
		this->_energyPoint -= 1;
		std::cout << BLUE << this->_name << RESET << " has no energy left, he can't attack" << std::endl;
		return ;
	}
	this->_energyPoint -= 1;

	std::cout << RED << "ClapTrap " << BLUE << this->_name << RED << " attacks " << BLUE << target << RED <<", causing "<< this->_attackDamage << " points of damage!" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoint <= 0)
	{
		std::cout << BLUE << this->_name << RESET << " Stop it, he is already dead..." << std::endl;
		return ;
	}

	this->_hitPoint -= amount;

	if (this->_hitPoint <= 0)
	{
		std::cout << BLUE << this->_name  << RESET << " is dead" << std::endl;
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoint <= 0)
	{
		std::cout << BLUE << this->_name << RESET << " is already dead, he can't repair himself" << std::endl;
		return ;
	}

	if (this->_energyPoint <= 0)
	{
		std::cout << BLUE << this->_name << RESET << " has no energy left, he can't repair himself" << std::endl;
		return ;
	}
	this->_energyPoint -= 1;
	std::cout << BLUE << this->_name << GREEN << " repair himself for " << amount << ", he was at " << this->_hitPoint << " hitpoint";
	this->_hitPoint += amount;
	std::cout << ", now he have " << this->_hitPoint << " hitpoint" << RESET << std::endl;
}