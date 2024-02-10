//
// Created by dbaule on 2/8/24.
//

#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>
# include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;


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

	void	complain(string level);
};

typedef void (Harl::*t_func)(void);

#endif
