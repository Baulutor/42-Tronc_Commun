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

// Method

void    BitcoinExchange::gettingBitcoin()
{
    std::string lineInput;

	while (getline(this->_fileDatabase, lineInput))
	{
		size_t		separate = lineInput.find(',');
		std::string date = lineInput.substr(0, separate);
		if (isdigit(lineInput[0]))
			this->_map.insert(std::pair<std::string, float>(date, atof(&lineInput[11])));
	}
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
			if (this->parsDate(dateInput))
				flag = this->parsValue(valueInput);
			if (flag == 1)
			{
				std::map<std::string, float>::iterator it = this->_map.find(dateInput);

				if (it != this->_map.end())
					std::cout << dateInput << " => " << valueInput << " = " << it->second * atof(valueInput.c_str()) << std::endl;
				else
				{
					it = _map.begin();
					while (it != _map.end() && strcmp(it->first.c_str(), dateInput.c_str()) < 0)
						it++;
					it--;
					std::cout << dateInput << " => " << valueInput << " = " << it->second * atof(valueInput.c_str()) << std::endl;
				}
			}
		}
		else if (flag == 0) // else ??
			std::cout << "Error: bad input => " << lineInput << std::endl;
    }

}

bool	BitcoinExchange::parsValue(std::string valueInput) // lol : penser au tab
{
	float	value = atof(valueInput.c_str());

	if (value < 0) // lol : comment differencier si atof a foire ou si j'ai mis 0 ? je peux mettre 0 ?
	{
		std::cout << "Error: the value can't be negative" << std::endl;
		return (0);
	}
	if (value > 1000)
	{
		std::cout << "Error: the value can't be beyond 1000" << std::endl;
		return (0);
	}
	return (1);
}

bool	BitcoinExchange::parsDate(std::string dateInput)
{
	std::string yearInput = dateInput.substr(0, 4);
	std::string monthInput = dateInput.substr(5, 2);
	std::string dayInput = dateInput.substr(8, 2);

	int year = atoi(yearInput.c_str());
	int month = atoi(monthInput.c_str());
	int day = atoi(dayInput.c_str());

	if (month == 0 || day == 0)
	{
		std::cout << "Error: Date cannot have 0 value, you need at least 1" << std::endl;
		return (0);
	}
	if (year < 2009 || (year == 2009 && day == 1 && month == 1))
	{
		std::cout << "Error: Bitcoin has been created the 2009-01-02, this is the minimum date accepted" << std::endl;
		return (0);
	}
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		{
			if (day > 31)
			{
				std::cout << "Error: The max number of day in a month is 31" << std::endl;
				return (0);
			}
			break;
		}
		case 4: case 6: case 9: case 11:
		{
			if (day > 30)
			{
				std::cout << "Error: in the month you selected, the max number is 30" << std::endl;
				return (0);
			}
			break;
		}
		case 2:
		{
			if (year % 4 == 0 && (year % 100 != 0 || (year % 400 == 0 && year % 100 == 0)))
			{
				if (day > 29)
				{
					std::cout << "Error: this is a leap year but you can't go beyond 29 for february" << std::endl;
					return (0);
				}
			}
			else if (day > 28)
			{
				std::cout << "Error: except for a leap year, you can't put beyond 28 in february" << std::endl;
				return (0);
			}
			break;
		}
		default:
		{
			std::cout << "Error: the month you put is out of bounds, put between 1 and 12" << std::endl;
			return (0);
		}
	}
	return (1);
}

bool	BitcoinExchange::parsString(std::string lineInput, bool flag)
{
	int		comptMinus = 0;
	int		comptBetweenMinus = 0;
	int		comptPoint = 0;

	for (size_t i = 0; lineInput[i]; i++)
	{
		if (lineInput[i] != '|' && lineInput[i] != ' ' && lineInput[i] != '-' && lineInput[i] != '.' && !isdigit(lineInput[i]))
			return (0);
		if (flag == 1)
		{
			if (this->checkValue(lineInput, &comptPoint, i) == 0)
				return (0);
		}
		if (lineInput[i] == '|' && flag == 0)
		{
			if (comptBetweenMinus != 3)
				return (0);
			flag = 1;
		}
		if (flag == 0 && !isdigit(lineInput[i]) && lineInput[i] != '-')
		{
			if (lineInput[i] == ' ' && lineInput[i + 1] != '|')
				return (0);
		}
		if (flag == 0 && (lineInput[i] == '-'))
		{
			comptMinus++;
			if (comptMinus > 2 || (comptMinus == 1 && comptBetweenMinus != 4) || (comptMinus != 1 && comptBetweenMinus != 2) || !isdigit(lineInput[i - 1]) || !isdigit(lineInput[i + 1]))
				return (0);
			comptBetweenMinus = -1;
		}
		if (flag == 1 && lineInput[i] == '|' && (i == 0 || lineInput[i - 1] != ' ' || (i < lineInput.length() && lineInput[i + 1] != ' ')))
			return (0);
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
	if (!isdigit(lineInput[i]) && lineInput[i] != '.' && lineInput[i] != ' ')
		return (0);
	if (lineInput[i] == '.')
		*comptPoint += 1;
	if (*comptPoint > 1)
		return (0);
	return (1);
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
