
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> stackIt;
    stackIt.push(5);
    stackIt.push(17);
    stackIt.push(3);
    stackIt.push(5);
    std::cout << std::endl << "Mutant stack size before pop()"  << stackIt.size() << std::endl;
    stackIt.pop();
	std::cout << "Mutant stack size after pop()"  << stackIt.size() << std::endl;
    stackIt.push(737);

    stackIt.push(0);
    MutantStack<int>::iterator it = stackIt.begin();

	std::cout << std::endl << "Non-const stack value when iterate: " << std::endl;
	for (; it != stackIt.end(); ++it)
		std::cout << *it << std::endl;


	std::cout << std::endl << "Const version:" << std::endl;
	const MutantStack<int> cStackIt = stackIt;

	MutantStack<int>::const_iterator cIt = cStackIt.begin();

	for (; cIt != cStackIt.end(); ++cIt)
		std::cout << *cIt << std::endl;
	stackIt.clearC();
    return 0;
}