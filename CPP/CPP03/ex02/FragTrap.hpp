#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <fstream>
# include <ostream>
# include "ClapTrap.hpp"

# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"

class	FragTrap :  public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap & src);
	FragTrap & operator=(FragTrap & rhs);
	~FragTrap();

	void highFivesGuys(void);
};

#endif