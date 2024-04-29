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
	try
	{
		while (test[i])
		{
			if (isdigit(test[i]) || test[i] == '+' || test[i] == '-' || test[i] == '*' || test[i] == '/' || test[i] == ' ')
			{
				if (test[i] != ' ')
				{
//					size_t l = test.find_first_not_of(' ', i);
					if (i == 0)
					{
						if (test[i + 1] && test[i + 1] != ' ')
							throw std::invalid_argument("Error: Wrong argument");
					}
//					if (test[i + 1] && test[l])
//					{
//						throw std::invalid_argument("Error: Wrong argument 26566");
//					}
				}
			}
			else
				throw std::invalid_argument("Error: Wrong argument");
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}