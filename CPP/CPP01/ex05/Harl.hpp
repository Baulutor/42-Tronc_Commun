//
// Created by dbaule on 2/8/24.
//

#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>
# include <fstream>

class	Harl{
private :
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public :
	//CONSTRUCTOR AND DESTRUCTOR
	Harl();
	~Harl();

	void	complain(std::string level);
};

typedef void (Harl::*t_func)(void);

#endif
