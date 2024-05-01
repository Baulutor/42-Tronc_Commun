//
// Created by dbaule on 4/29/24.
//

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <exception>
# include <stack>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class RPN {
private :
	std::stack<int> _myStack;
public :
	// CONSTRUCTOR DESTRUCTOR
	RPN();
	RPN(RPN &src);
	RPN &operator=(RPN &rhs);
	~RPN();

	// GETTER
	size_t	sizeOfStack() const;
	int 	topOfStack() const;

	// METHOD
	void		operation(char ope);
	void		pushInStack(int buf);
	std::string	pars(int argc, char **argv);
};


#endif
