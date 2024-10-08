//
// Created by dbaule on 2/10/24.
//

#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::complain(std::string level)
{
	t_func		func[] = {&Harl::debug, &Harl::error, &Harl::warning, &Harl::info};
	std::string	harlComplain[4] = {"DEBUG", "ERROR", "WARNING", "INFO"};
	int i = 0;

	while (i < 4)
	{

		if (!harlComplain[i].compare(level))
			return ((this->*func[i])());
		i++;
	}

}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
