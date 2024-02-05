//
// Created by dbaule on 1/22/24.
//

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	cout << "Constructor called" << endl;
	return ;
}

PhoneBook::~PhoneBook(){
	cout << "Destructor called" << endl;
	return ;
}

void	PhoneBook::add(int i)
{
	string str;

	do {
		cout << "Enter your First Name : ";
		std::getline(std::cin, str);
	} while (!cin.eof() && str.length() == 0);
	if (cin.eof())
		return ;
	this->_contacts[i].setFirstName(str);
	do {
		cout << "Enter your Last Name : ";
		std::getline(std::cin, str);
	} while (!cin.eof() && str.length() == 0);
	if (cin.eof())
		return ;
	this->_contacts[i].setLastName(str);
	do {
		cout << "Enter your Nickname : ";
		std::getline(std::cin, str);
	} while (!cin.eof() && str.length() == 0);
	if (cin.eof())
		return ;
	this->_contacts[i].setNickName(str);
	do {
		cout << "Enter your Phone Number : ";
		std::getline(std::cin, str);
	}while (!cin.eof() && str.length() == 0);
	if (cin.eof())
		return ;
	this->_contacts[i].setPhoneNumber(str);
	do {
		cout << "Enter your Darkest Secret : ";
		std::getline(std::cin, str);
	}while ((!cin.eof() && str.length() == 0));
	if (cin.eof())
		return ;
	this->_contacts[i].setDarkestSecret(str);
}

string	PhoneBook::troncFunction(string str)
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + ".");
}

int PhoneBook::isOnlyDigits(string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

void	PhoneBook::specificContact()
{
	string	str;
	string	buf;
	int 	ind = 0;

	do {
		cout << "Search for a specific contact? insert his index : ";
		std::getline(std::cin, str);
	}while ((!cin.eof() && str.length() == 0));
	if (cin.eof())
		return ;
	if (isOnlyDigits(str))
		std::istringstream(str) >> ind;
	else
	{
		cout << "Exit SEARCH, wrong index" << endl;
		return ;
	}
	if (ind < 1 ||ind > NBR_CONT)
	{
		cout << "Exit SEARCH, wrong index" << endl;
		return ;
	}
	if (this->_contacts[ind - 1].getFirstName() == "")
		cout << "There is no user in this index, exit SEARCH" << endl;
	else
	{
		cout << "Firstname : " << this->_contacts[ind - 1].getFirstName() << endl;
		cout << "Lastname : " << this->_contacts[ind - 1].getLastName() << endl;
		cout << "NickName : " << this->_contacts[ind - 1].getNickName() << endl;
		cout << "PhoneNumber : " << this->_contacts[ind - 1].getPhoneNumber() << endl;
		cout << "DarkestSecret : " << this->_contacts[ind - 1].getDarkestSecret() << endl;
	}
};

void	PhoneBook::search()
{
	string	firstName;
	string	lastName;
	string	nickName;

	cout << "-------------------CONTACTS------------------" << endl;
	for (int i = 0; i < NBR_CONT; i++)
	{
		firstName = troncFunction(this->_contacts[i].getFirstName());
		lastName = troncFunction(this->_contacts[i].getLastName());
		nickName = troncFunction(this->_contacts[i].getNickName());
		cout << "|" << std::setw(5) << this->_contacts[i].getIndex() << std::setw(6);
		cout << "|" << std::setw(10) << firstName;
		cout << "|" << std::setw(10) << lastName;
		cout << "|" << std::setw(10) << nickName << "|" << endl;
	}
	cout << "---------------------------------------------" << endl;
	specificContact();
}

void	PhoneBook::setAllIndex()
{
	for(int i = 0; i < NBR_CONT; i++)
		this->_contacts[i].setIndex(i);
};
