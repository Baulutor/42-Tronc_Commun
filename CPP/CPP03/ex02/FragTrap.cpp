#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	cout << "Default constructor FragTrap called" << endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{

}

//FragTrap &FragTrap::operator=(FragTrap &rhs)
//{
//
//}

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