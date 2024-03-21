//
// Created by dbaule on 3/18/24.
//

#include "Bureaucrat.hpp"


int main ()
{
	try
	{
		Bureaucrat bur;

		std::cout << bur << std::endl;
		bur.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat ceo("CEO", 1);
		std::cout << BLUE << ceo << RESET <<std::endl;
		ceo.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat executive("Pat", 75);

		std::cout << GREEN << executive << RESET <<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}


// the cases where the Bureaucrat is catch
	try
	{
		Bureaucrat godFather("Erik", 0);

		std::cout << godFather << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bur("Claude", 1510000000);

		std::cout << bur << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

