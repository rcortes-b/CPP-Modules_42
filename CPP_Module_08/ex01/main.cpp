#include "includes/Span.hpp"

/*

This is the subject main

int	main(void)
{
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}*/

/* This is a custom main */

//#include <time.h>
#define N_AMOUNT 12000
int main(void)
{
	try {
		Span sp = Span(N_AMOUNT);
		srand(time(NULL));
		for (unsigned int i = 0; i < N_AMOUNT; i++)
			sp.addNumber(rand());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp1 = Span(N_AMOUNT);
		srand(time(NULL));
		for (unsigned int i = 0; i < N_AMOUNT - 10; i++)
			sp1.addNumber(rand());
		std::cout << "Container size before: " << sp1.getContainer().size() << std::endl;
		sp1.fillNumbers();
		std::cout << "Container size after: " << sp1.getContainer().size() << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
