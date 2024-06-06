
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    std::cout << std::endl << "Mutant stack size before pop()"  << mstack.size() << std::endl;
    mstack.pop();
	std::cout << "Mutant stack size after pop()"  << mstack.size() << std::endl;
    mstack.push(737);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();

	std::cout << std::endl << "les valeurs de stack en iterant: " << std::endl;
	for (; it != mstack.end(); ++it)
		std::cout << *it << std::endl;

    return 0;
}