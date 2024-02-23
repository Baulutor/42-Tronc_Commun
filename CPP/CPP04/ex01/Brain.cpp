
#include "Brain.hpp"



Brain::Brain() :
{
	cout << "Default Brain constructor Called" << endl;
}

Brain &Brain::operator=(Brain &rhs)
{
	if (this != &rhs)
	{
		this->_ideas = rhs._ideas;
	}
	return (*this);
}

Brain::Brain(Brain &src)
{
	this->_ideas = src._ideas;
}


Brain::~Brain()
{
	cout << "Brain Destructor called" << endl;
}
