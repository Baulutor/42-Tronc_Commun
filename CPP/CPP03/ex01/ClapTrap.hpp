#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <fstream>
# include <ostream>

# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"

class	ClapTrap
{
protected:
	std::string			_name;
	int 			_hitPoint;
	int 			_energyPoint;
	unsigned int 	_attackDamage;

public:

	// CONSTRUCTOR AND DESTRUCTOR;
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hitpoint, int energypoint, unsigned int attdmg);
	ClapTrap(ClapTrap & src);
	ClapTrap & operator=(ClapTrap & rhs);
	~ClapTrap();

	// GETTER AND SETTER
	std::string 	getName();
	int 	getHitPoint();
	int 	getEnergyPoint();
	int 	getAttackDamage();

	void 	setHitPoint(int admg);
	void 	setEnergyPoint(int newep);
	void 	setAttackDamage(int newad);
	// METHOD
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


#endif