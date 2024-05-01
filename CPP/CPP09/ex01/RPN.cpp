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

// GETTER

size_t	RPN::sizeOfStack() const
{
	return (this->_myStack.size());
}

int 	RPN::topOfStack() const
{
	return (_myStack.top());
}

void	RPN::pushInStack(int buf)
{
	_myStack.push(buf);
}

std::string RPN::pars(int argc, char **argv)
{
	if (argc != 2)
		throw std::invalid_argument("Error: Please put one and only one parameter to the RPN");
	std::string	str = argv[1];
	if (str.find_first_not_of("0142356789+-*/ ") != str.npos)
		throw std::invalid_argument("Error: Wrong character(s) in the argument you send, put only digit, space and operator");
	return (str);
}

void	RPN::operation(char ope)
{
	if (_myStack.size() < 2)
		throw std::length_error("Error: Wrong argument, there is at least one number missing before the operator");
	else if (ope == '+')
	{
		int buf = _myStack.top();
		_myStack.pop();
		int buf2 = _myStack.top() + buf;
		_myStack.pop();
		_myStack.push(buf2);
	}
	else if (ope == '-')
	{
		int buf = _myStack.top();
		_myStack.pop();
		int buf2 = _myStack.top() - buf;
		_myStack.pop();
		_myStack.push(buf2);
	}
	else if (ope == '/')
	{
		int buf = _myStack.top();
		if (buf == 0)
			throw std::invalid_argument("Error: Cannot divide by 0");
		_myStack.pop();
		if (_myStack.top() == 0)
			throw std::invalid_argument("Error: Cannot divide by 0");
		int buf2 = _myStack.top() / buf;
		_myStack.pop();
		_myStack.push(buf2);
	}
	else if (ope == '*')
	{
		int buf = _myStack.top();
		_myStack.pop();
		int buf2 = _myStack.top() * buf;
		_myStack.pop();
		_myStack.push(buf2);
	}
}