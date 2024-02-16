#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap() {

}

ScavTrap::ScavTrap(string name) : ClapTrap(name, 100, 50, 20)
{
//	(void)name;
	cout << "ScavTrap " << BLUE << this->_name << RESET << " Default constructor called"  << endl;
}


ScavTrap::ScavTrap(ScavTrap & src)
{
	this->_name = src.getName();
	this->_hitPoint = src.getHitPoint();
	this->_attackDamage = src.getAttackDamage();
	this->_energyPoint = src.getEnergyPoint();
	cout << "Copy constructor of " << BLUE << this->_name << RESET << " called" << endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap & rhs)
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

ScavTrap::~ScavTrap()
{
	cout << "Destructor of ScavTrap " << BLUE << this->_name << RESET << " called" << endl;
}


void	ScavTrap::guardGate() {
	cout << BLUE << this->_name << YELLOW << " is now on guard gate mod" << RESET << endl;
}

void	ScavTrap::attack(const std::string& target)
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

	cout << RED << "ScavTrap " << BLUE << this->_name << RED << " attacks " << target << " , causing "<< this->_attackDamage << " points of damage!" << RESET << endl;
}