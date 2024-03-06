#include "ClapTrap.hpp"


int main ()
{
	ClapTrap first("Foo");
	ClapTrap second("FooFoo");
	ClapTrap third("FooFooFoo");

	second.attack(first.getName());
	second.setAttackDamage(10);
	second.attack(first.getName());
	first.takeDamage(second.getAttackDamage());
	first.attack(second.getName());
	first.beRepaired(10);
	second.beRepaired(10);

	third.setAttackDamage(1);
	for (int i = 0; i < 12; i++)
	{
		third.attack(second.getName());
		if (third.getEnergyPoint() >= 0)
			second.takeDamage(third.getAttackDamage());
	}
	std::cout << BLUE << second.getName() << RESET << " still have " << second.getHitPoint() << " hitpoints" << std::endl;
}
