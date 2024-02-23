#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	cout << "Default constructor FragTrap called" << endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{

}

FragTrap::FragTrap(FragTrap & src)
{
	this->_name = src.getName();
	this->_hitPoint = src.getHitPoint();
	this->_attackDamage = src.getAttackDamage();
	this->_energyPoint = src.getEnergyPoint();
	cout << "Copy constructor of " << BLUE << this->_name << RESET << " called" << endl;
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
	cout << "Copy assignment operator " << BLUE << this->_name << RESET << " called" << endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	cout << "Destructor of FragTrap " << BLUE << this->_name << RESET << " called" << endl;
}

void FragTrap::highFivesGuys()
{
	string	getInput;
	if (this->_hitPoint <= 0)
	{
		cout << BLUE << this->_name << RESET << " is dead, he can't make highfive :(" << endl;
		return ;
	}
	do
	{
		cout << "do you want to HighFive Frag ? Press Y if yes, or N if no" << endl;
		getline(cin, getInput);

	}while (!cin.eof() && !getInput.find_first_not_of("YN"));
	if (cin.eof())
		return ;
	if (getInput[0] == 'Y')
		cout << BLUE << this->_name << RESET << CYAN << " doing an High five !" << RESET << endl;
	else
		cout << BLUE << this->_name << RED << " is very very sad !" << RESET << endl;
}
