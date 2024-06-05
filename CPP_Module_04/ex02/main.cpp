#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/Brain.hpp"

int main( void )
{
	Animal *animal[100];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << "Before: " << animal[4]->getBrain()->getIdea(5) << std::endl;
	animal[4]->getBrain()->setIdea("this is my idea !", 5);
	std::cout << "After: " << animal[4]->getBrain()->getIdea(5) << std::endl;

	for (int i = 0; i < 10; i++)
		delete animal[i];

	return 0;
}
