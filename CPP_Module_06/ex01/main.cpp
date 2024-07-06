#include "includes/Serializer.hpp"

/* uintptr_t es una direccion que puede almacenar otra direccion sin importar la que sea,
entonces cuando se recastea a t_Data en deseralize devuelve la direccion que habia almacenado anteriormente */

int main(void)
{
	t_Data	data;
	data.c = 'a';
	data.garbage = 5;
	t_Data	*dataptr = &data;
	uintptr_t	storage;
	std::cout << "Before: " << dataptr->c << " " << dataptr->garbage << std::endl;
	std::cout << "This is the data address: " << &data << std::endl;
	std::cout << "This is the uintptr_t storage address: " << &storage << std::endl << std::endl;

	storage = Serializer::serialize(dataptr);

	std::cout << "This is the uintptr_t storage address: " << &storage << std::endl;
	std::cout << "This is the data address: " << &data << std::endl << std::endl;
	std::cout << "This is the return adress of the function: " << &*(Serializer::deserialize(storage)) << std::endl << std::endl;
	dataptr = Serializer::deserialize(storage);
	std::cout << "This is the data address: " << &dataptr << std::endl;
	std::cout << "This is the uintptr_t storage address: " << &storage << std::endl;
	std::cout << "After: " << dataptr->c << " " << dataptr->garbage << std::endl;
	return (0);
}