#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main ()
{
	ClapTrap 	first("Foo");
	ClapTrap 	second("FooFoo");
	ClapTrap 	third("FooFooFoo");
	ScavTrap	scav("Terminator");
	FragTrap	frag("Frag");

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

	scav.guardGate();
	second.setAttackDamage(30);
	second.attack(scav.getName());
	scav.takeDamage(second.getAttackDamage());
	scav.attack(first.getName());
	first.takeDamage(scav.getAttackDamage());
	scav.attack(second.getName());
	second.takeDamage(scav.getAttackDamage());
	scav.guardGate();
	scav.attack(third.getName());
	third.takeDamage(scav.getAttackDamage());
	scav.attack(frag.getName());
	frag.takeDamage(scav.getAttackDamage());
	frag.highFivesGuys();
}
