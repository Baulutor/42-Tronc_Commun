
#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <cctype>
# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
	// CONSTRUCTOR AND DESTRUCTOR
		Weapon(std::string name);
		~Weapon();
	// SETTER AND GETTER
		const	std::string &getType();
		void	setType(std::string type);
};

#endif
