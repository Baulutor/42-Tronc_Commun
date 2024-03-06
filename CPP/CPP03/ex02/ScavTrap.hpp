#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <fstream>
# include <ostream>
# include "ClapTrap.hpp"

# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"

class	ScavTrap :  public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap & src);
	ScavTrap & operator=(ScavTrap & rhs);
	~ScavTrap();

	void	guardGate();
	void	attack(const std::string& target);
};

#endif