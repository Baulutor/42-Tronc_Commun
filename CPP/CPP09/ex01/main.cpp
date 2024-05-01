//
// Created by dbaule on 4/29/24.
//

#include "RPN.hpp"


int main (int argc, char **argv)
{
	RPN myStack;
	try
	{
		size_t i = 0;
		std::string	str = myStack.pars(argc, argv);
		while (str[i])
		{
			if (str[i] != ' ')
			{
				if (str.size() != i + 1 && str[i + 1] != ' ')
					throw std::invalid_argument("Error: Wrong argument, please put one space between your numbers and operator");
			}
			if (isdigit(str[i]))
			{
				int buf = str[i] - 48;
				myStack.pushInStack(buf);
			}
			if (str[i] == '-' || str[i] == '+' || str[i] == '/' || str[i] == '*')
				myStack.operation(str[i]);
			i++;
		}
		if (myStack.sizeOfStack() > 1)
			throw std::invalid_argument("Error: Operators are missing, there should be more operator");
		std::cout << GREEN << myStack.topOfStack() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}