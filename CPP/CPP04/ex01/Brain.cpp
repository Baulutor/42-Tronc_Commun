//
// Created by dbaule on 3/1/24.
//

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Default Brain constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "idea";
	}
}

Brain::Brain(std::string oneIdea)
{
	std::cout << GREEN << "Brain constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = oneIdea;
	}
}

Brain::Brain(Brain &src)
{
	(void)src;
	std::cout << GREEN << "Copy Brain constructor called" << RESET << std::endl;
//	this._ideas = src._ideas;
}


Brain::~Brain()
{
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
}
