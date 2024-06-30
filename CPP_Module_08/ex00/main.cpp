#include "includes/easyfind.hpp"

int main(void)
{
	//Declare a vector container of int
	//std::vector<int> proof(3, 0);
	std::vector<int> proof;

	/* Initialize the container with the push_back
	(add the integer passed as parameter at the end of the vector) */
	proof.push_back(4);
	proof.push_back(7);
	proof.push_back(10);

	/* Should throw exception */

	try {
		easyfind(proof, 11);
	}
	catch (NumberNotFound &a) {
		std::cout << a.what() << std::endl; 
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	/* Should work */

	try {
		easyfind(proof, 10);
	}
	catch (NumberNotFound &a) {
		std::cout << a.what() << std::endl; 
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}