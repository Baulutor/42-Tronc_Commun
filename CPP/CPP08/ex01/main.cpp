//
// Created by dbaule on 4/15/24.
//

#include "Span.hpp"


int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

//int main()
//{
//    Span test(90);
//
//    try
//    {
//        test.fillVector();
//        std::cout << "shortest Span : "<< test.shortestSpan() << std::endl;
//        std::cout << "longest Span : " << test.longestSpan() << std::endl;
//    }
//    catch(std::exception &e)
//    {
//        std::cout << e.what() << std::endl;
//    }
//
//    return (0);
//}
