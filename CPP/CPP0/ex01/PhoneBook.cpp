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

	cout << "Enter your First Name : ";
	std::getline(std::cin, str);
	this->_contacts[i].setFirstName(str);
	cout << "Enter your Last Name : ";
	std::getline(std::cin, str);
	this->_contacts[i].setLastName(str);
	cout << "Enter your Nickname : ";
	std::getline(std::cin, str);
	this->_contacts[i].setNickName(str);
	cout << "Enter your Phone Number : ";
	std::getline(std::cin, str);
	this->_contacts[i].setPhoneNumber(str);
	cout << "Enter your Darkest Secret : ";
	std::getline(std::cin, str);
	this->_contacts[i].setDarkestSecret(str);
}

void	PhoneBook::search()
{
	cout << "-------------------CONTACTS------------------" << endl;
	for (int i = 0; i < NBR_CONT; i++)
	{
		cout << "|" << std::setw(5) << this->_contacts[i].getIndex() << std::setw(6);
		cout << "|" << std::setw(5) << this->_contacts[i].getFirstName() << std::setw(6);
		cout << "|" << std::setw(5) << this->_contacts[i].getLastName() << std::setw(6);
		cout << "|" << std::setw(5) << this->_contacts[i].getNickName() << std::setw(6)  << "|" << endl;
	}
	cout << "---------------------------------------------" << endl;
}

void	PhoneBook::setAllIndex()
{
	for(int i = 0; i < NBR_CONT; i++)
		this->_contacts[i].setIndex(i);
};
