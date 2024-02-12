//
// Created by dbaule on 1/22/24.
//

#ifndef CPP_PHONEBOOK_H
#define CPP_PHONEBOOK_H

#include "Contact.hpp"

#include <cctype>
#include <string>
#include <iostream>
#include <iomanip>

# define NBR_CONT 8


using std::cout;
using std::endl;
using std::string;
using std::cin;

class PhoneBook
{
	private :
		Contact		_contacts[8];
	public :
	// CONSTRUCTOR DESTRUCTOR
					PhoneBook(void);
					~PhoneBook(void);

	// GETTER SETTER
//		void		initName(string str);
		void		setAllIndex();
	// METHODS
		void		add(int i);
		void		search();
		string		troncFunction(string str);
		void		specificContact();
		int 		isOnlyDigits(string str);
		int 		stringToInt(const std::string& str);
		int 		checkSpace(string str);
};



#endif //CPP_PHONEBOOK_H
