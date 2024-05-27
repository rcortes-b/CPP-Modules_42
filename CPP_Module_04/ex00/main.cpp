#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

/* Virtual is the key, depende de si es virtual el cual te permite elegir se printa un mensaje u otro !! */

int main( void )
{
	WrongAnimal* meta = new WrongAnimal();
	Animal* j = new Dog();
	WrongAnimal* i = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete j;
	delete i;
	delete meta;
return 0;
}