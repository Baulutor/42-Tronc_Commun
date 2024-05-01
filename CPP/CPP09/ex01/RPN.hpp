//
// Created by dbaule on 4/29/24.
//

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <exception>
# include <stack>

class RPN {
private :
public :
	// CONSTRUCTOR DESTRUCTOR
	RPN();
	RPN(RPN &src);
	RPN &operator=(RPN &rhs);
	~RPN();
};

void	operation(std::stack *myStack, char ope);

#endif
