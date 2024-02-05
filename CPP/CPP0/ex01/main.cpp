#include "PhoneBook.hpp"

int main ()
{
	PhoneBook inst;
	string	str;
	int i = 0;

	cout << "Welcome to your PhoneBook" << endl;
	cout << "MENU:" << endl;
	cout << "You can add a contact by using ADD" << endl;
	cout << "You can search for a contact by using SEARCH" << endl;
	cout << "You can also quit it by using EXIT" << endl;
	std::getline(std::cin, str);
	inst.setAllIndex();
	while (str.compare("EXIT") != 0 && !std::cin.eof())
	{
		if (str.compare("ADD") == 0)
		{
			inst.add(i);
			i++;
			if (i == NBR_CONT)
				i = 0;
		}
		if (str.compare("SEARCH") == 0)
			inst.search();
		if (str.length() != 0 && !cin.eof())
		{
			cout << "MENU:" << endl;
			cout << "You can add a contact by using ADD" << endl;
			cout << "You can search for a contact by using SEARCH" << endl;
			cout << "You can also quit it by using EXIT" << endl;
		}
		std::getline(std::cin, str);
	}
	cout << endl << "Exit PhoneBook" << endl;
	return (0);
}
