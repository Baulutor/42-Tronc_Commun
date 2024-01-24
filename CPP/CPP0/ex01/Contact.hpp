//HEADERD E 42 DBAULE CREATED BYU DBAULE MODIFIED BY DBAULE

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>


using std::cout;
using std::endl;
using std::string;

class Contact
{
	private:
		string	_firstName;
		string	_lastName;
		string	_nickName;
		string	_phoneNumber;
		string	_darkestSecret;
		int		_index;

	public:

	// CONSTRUCTOR DESTRUCTOR
				Contact(void);
				~Contact(void);
	// GETTER SETTER
		void	setFirstName(string str);
		void	setLastName(string str);
		void	setNickName(string str);
		void	setPhoneNumber(string str);
		void	setDarkestSecret(string str);
		void	setIndex(int i);


		string	getFirstName();
		string	getLastName();
		string	getNickName();
		int 	getIndex();


		string	getName();

};

#endif