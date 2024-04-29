//
// Created by dbaule on 4/29/24.
//

#include "RPN.hpp"


RPN::RPN()
{

}

RPN::RPN(RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(RPN &rhs)
{
	if (this != &rhs)
	{

	}
	return (*this);
}

RPN::~RPN()
{

}