#include "includes/RealType.hpp"

int	main(void)
{
	std::cout << "\n------------------" << std::endl;
	std::cout << "Using Base Pointer" << std::endl;
	std::cout << "------------------\n" << std::endl;

	Base *pPtr = generate();
	identify(pPtr);
	identify(*pPtr);
	delete pPtr;

	std::cout << std::endl;
	sleep(5);

	std::cout << "--------------------" << std::endl;
	std::cout << "Using Base Reference" << std::endl;
	std::cout << "--------------------\n" << std::endl;

	Base *pRef_aux = generate();
	Base &pRef = *pRef_aux;
	identify(&pRef);
	identify(pRef);
	delete pRef_aux;

	std::cout << std::endl;

	return (0);
}