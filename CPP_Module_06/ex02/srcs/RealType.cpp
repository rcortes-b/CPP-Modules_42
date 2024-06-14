#include "../includes/RealType.hpp"

Base	*generate(void)
{
	Base	*p = NULL;

	srand(time(NULL));
	unsigned int choice = rand() % 3;
	switch (choice) {
		case 0:
				std::cout << "Class A has been generated !" << std::endl;
				p = dynamic_cast<Base*>(new A);
				return (p);
		case 1:
				std::cout << "Class B has been generated !" << std::endl;
				p = dynamic_cast<Base*>(new B);
				return (p);
		case 2:
				std::cout << "Class C has been generated !" << std::endl;
				p = dynamic_cast<Base*>(new C);
				return (p);
		default:
				std::cerr << "Random number generator went crazy !" << std::endl;
	}
	return (NULL);
}

void	identify(Base *p)
{
	if(dynamic_cast<const A*>(p))
        std::cout << "A" << std::endl;
	else if (dynamic_cast<const B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<const C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Not a defined type !" << std::endl;
}

void	identify(Base &p)
{
    if (dynamic_cast<const A*>(&p))
        std::cout << "A" << std::endl;
	else if (dynamic_cast<const B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<const C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Not a defined type !" << std::endl;
}