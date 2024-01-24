

#include "Contact.hpp"

Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_darkestSecret = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	return ;
}

Contact::~Contact()
{
	return ;
}

void	Contact::setFirstName(string str)
{
	this->_firstName = str;
}

void	Contact::setLastName(string str)
{
	this->_lastName = str;
}

void	Contact::setNickName(string str)
{
	this->_nickName = str;
}

void	Contact::setPhoneNumber(string str)
{
	this->_phoneNumber = str;
}

void	Contact::setDarkestSecret(string str)
{
	this->_darkestSecret = str;
}

void	Contact::setIndex(int i)
{
	this->_index = i;
	return ;
}

string	Contact::getFirstName()
{
	return  this->_firstName;
}

string	Contact::getLastName()
{
	return this->_lastName;
}

string	Contact::getNickName()
{
	return this->_nickName;
}

int		Contact::getIndex()
{
	return this->_index + 1;
}
