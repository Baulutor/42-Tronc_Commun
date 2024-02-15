#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <fstream>
# include <ostream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

class	ClapTrap
{
private:
	string	_name;
	int 	_hitPoint = 10;
	int 	_energyPoint = 10;
	int 	_attackDamage = 0;

public:

	// CONSTRUCTOR AND DESTRUCTOR
	ClapTrap();
	ClapTrap(ClapTrap const & src);
	ClapTrap & operator=(ClapTrap & rhs);
	~ClapTrap();
	// METHOD
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


#endif