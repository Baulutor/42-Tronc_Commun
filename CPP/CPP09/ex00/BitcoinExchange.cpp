//
// Created by dbaule on 4/22/24.
//

#include "BitcoinExchange.hpp"


// Constructor and Destructor

BitcoinExchange::BitcoinExchange()
{
    this->_fileDatabase.open("data.csv");
    this->_fileInput.open("input.txt");
    if (this->_fileInput.is_open() == false)
        throw (cantOpenInput());
    if (!this->_fileDatabase.is_open())
        throw (cantOpenDatabase());
}

BitcoinExchange::BitcoinExchange(const char *input)
{
    this->_fileDatabase.open("data.csv");
    this->_fileInput.open(input);
    if (this->_fileInput.is_open() == false)
        throw (cantOpenInput());
    if (!this->_fileDatabase.is_open())
        throw (cantOpenDatabase());
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &rhs)
{
    if (this != &rhs)
    {

    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    if (this->_fileDatabase.is_open())
        this->_fileDatabase.close();
    if (this->_fileInput.is_open())
        this->_fileInput.close();
}

// Getter and Setter


// Method

void    BitcoinExchange::gettingBitcoin()
{
    std::string lineInput;
    while (getline(this->_fileInput, lineInput))
    {
        bool	flag = 0;
		if (lineInput.find_first_not_of("|") != lineInput.npos)
			flag = this->parsString(lineInput, flag);
        if (flag == 1)
		{
			size_t	separate = lineInput.find('|');
			std::string dateInput = lineInput.substr(0, separate - 1);
			std::string	valueInput = lineInput.substr(separate + 2);
			std::cout << dateInput << " okok " << valueInput << std::endl;
		}
		else if (flag == 0)
			std::cout << "Error: bad input => " << lineInput << std::endl;
    }
}

bool	BitcoinExchange::parsString(std::string lineInput, bool flag)
{
	int		comptMinus = 0;
	int		comptBetweenMinus = 0;
	int		*comptPoint = 0;
	for (size_t i = 0; lineInput[i]; i++)
	{
		if (lineInput[i] != '|' && lineInput[i] != ' ' && lineInput[i] != '-' && lineInput[i] != '.' && !isdigit(lineInput[i]))
		{
			flag = 0;
			break;
		}
		if (flag == 1)
		{
			if (this->checkValue(lineInput, comptPoint, i) == 0)
				break;
		}
		if (lineInput[i] == '|' && flag == 0)
		{
			if (comptBetweenMinus != 3)
				break;
			flag = 1;
		}
		if (flag == 0 && !isdigit(lineInput[i]) && lineInput[i] != '-')
		{
			if (lineInput[i] == ' ' && lineInput[i + 1] != '|')
				break;
		}
		if (flag == 0 && (lineInput[i] == '-'))
		{
			comptMinus++;
			if (comptMinus > 2 || (comptMinus == 1 && comptBetweenMinus != 4) || (comptMinus != 1 && comptBetweenMinus != 2) || !isdigit(lineInput[i - 1]) || !isdigit(lineInput[i + 1]))
				break;
			comptBetweenMinus = -1;
		}
		if (flag == 1 && lineInput[i] == '|' && (i == 0 || lineInput[i - 1] != ' ' || (i < lineInput.length() && lineInput[i + 1] != ' ')))
		{
			flag = 0;
			break;
		}
		comptBetweenMinus++;
	}
	if (comptMinus < 2)
		flag = 0;
	return (flag);
}

bool	BitcoinExchange::checkValue(std::string lineInput, int *comptPoint, int i)
{
	if ((lineInput[i] == ' ' && lineInput[i - 1] != '|'))
		return (0);
	if (!isdigit(lineInput[i]) && lineInput[i] != '.')
		return (0);
	if (lineInput[i] == '.')
		*comptPoint += 1;
	if (*comptPoint > 1)
		return (0);
	return (1);
}

void    BitcoinExchange::checkDate()
{

}

// Exception

const char  *BitcoinExchange::cantOpenDatabase::what() const throw()
{
    return ("Failed to open the database please verify if there is this file : or verify if anyone can open to read");
}

const char  *BitcoinExchange::cantOpenInput::what() const throw()
{
    return ("Failed to open the Input please verify is the file exist, or verify if anyone can open to read");
}
