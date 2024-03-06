#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{

}

FragTrap::FragTrap(FragTrap & src) : ClapTrap()
{
	this->_name = src.getName();
	this->_hitPoint = src.getHitPoint();
	this->_attackDamage = src.getAttackDamage();
	this->_energyPoint = src.getEnergyPoint();
	std::cout << "Copy constructor of " << BLUE << this->_name << RESET << " called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap & rhs)
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

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap " << BLUE << this->_name << RESET << " called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::string	getInput;
	if (this->_hitPoint <= 0)
	{
		std::cout << BLUE << this->_name << RESET << " is dead, he can't make highfive :(" << std::endl;
		return ;
	}
	do
	{
		std::cout << "do you want to HighFive Frag ? Press Y if yes, or N if no" << std::endl;
		getline(std::cin, getInput);

	}while (!std::cin.eof() && !getInput.find_first_not_of("YN"));
	if (std::cin.eof())
		return ;
	if (getInput[0] == 'Y')
		std::cout << BLUE << this->_name << CYAN << " doing an High five !" << RESET << std::endl;
	else
		std::cout << BLUE << this->_name << RED << " is very very sad !" << RESET << std::endl;
}
