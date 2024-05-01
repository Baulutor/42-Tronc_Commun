//
// Created by dbaule on 4/29/24.
//

#include "RPN.hpp"


int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Please put one and only one parameter to the RPN" << std::endl;
		return (1);
	}
	size_t i = 0;
	std::string	test = argv[1];
	std::stack<int> myStack;
	try
	{
		if (test.find_first_not_of("0142356789+-*/ ") != test.npos)
			throw std::invalid_argument("Error: Wrong argument");
		while (test[i])
		{
			if (test[i] != ' ')
			{
				if (test.size() >= i + 1 && test[i + 1] != ' ' && i > 0 && test[i - 1] != ' ')
					throw std::invalid_argument("Error: Wrong argument");
			}
			if (isdigit(test[i]))
			{
				int buf = test[i] - 48;
				myStack.push(buf);
			}
			if (test[i] == '-' || test[i] == '+' || test[i] == '/' || test[i] == '*')
			{
				operation(&myStack, test[i]);
			}
			i++;
		}
		if (myStack.size() > 1)
			throw std::invalid_argument("Error: Wrong number of operation");
		std::cout << myStack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}