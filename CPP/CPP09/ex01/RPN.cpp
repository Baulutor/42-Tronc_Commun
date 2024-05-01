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

void	operation(std::stack *myStack, char ope)
{
	if (myStack->size() < 2)
		throw std::length_error("Error: Wrong argument, need at least 2 number before make an operation");
	else if (ope == '+')
	{
		int buf = myStack->top();
		myStack->pop();
		int buf2 = myStack->top() + buf;
		myStack->pop();
		myStack->push(buf2);
	}
	else if (ope == '-')
	{
		int buf = myStack->top();
		myStack->pop();
		int buf2 = myStack->top() - buf;
		myStack->pop();
		myStack->push(buf2);
	}
	else if (ope == '/')
	{
		int buf = myStack->top();
		if (buf == 0)
			throw std::invalid_argument("Error: Cannot divide by 0");
		myStack->pop();
		if (myStack->top() == 0)
			throw std::invalid_argument("Error: Cannot divide by 0");
		int buf2 = myStack->top() / buf;
		myStack->pop();
		myStack->push(buf2);
	}
	else if (ope == '*')
	{
		int buf = myStack->top();
		myStack->pop();
		int buf2 = myStack->top() * buf;
		myStack->pop();
		myStack->push(buf2);
	}
}