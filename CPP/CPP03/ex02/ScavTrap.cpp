#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << BLUE << this->_name << RESET << " Default constructor called"  << std::endl;

}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << BLUE << this->_name << RESET << " Constructor called"  << std::endl;
}


ScavTrap::ScavTrap(ScavTrap & src) : ClapTrap()
{
	this->_name = src.getName();
	this->_hitPoint = src.getHitPoint();
	this->_attackDamage = src.getAttackDamage();
	this->_energyPoint = src.getEnergyPoint();
	std::cout << "Copy constructor of " << BLUE << this->_name << RESET << " called" << std::endl;
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
	std::cout << "Copy assignment operator " << BLUE << this->_name << RESET << " called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap " << BLUE << this->_name << RESET << " called" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << BLUE << this->_name << YELLOW << " is now on guard gate mod" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target)
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

	std::cout << RED << "ScavTrap " << BLUE << this->_name << RED << " attacks " << BLUE << target << RED << ", causing "<< this->_attackDamage << " points of damage!" << RESET << std::endl;
}