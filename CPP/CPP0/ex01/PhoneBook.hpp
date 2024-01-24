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
};



#endif //CPP_PHONEBOOK_H
