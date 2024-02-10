
#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <cctype>
# include <string>
# include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

class Weapon
{
	private:
		string	_type;
	public:
	// CONSTRUCTOR AND DESTRUCTOR
		Weapon(string name);
		~Weapon();
	// SETTER AND GETTER
		const	string &getType();
		void	setType(string type);
};

#endif
