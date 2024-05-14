#include "file.hpp"

int main(int argc, char **argv)
{
	std::fstream	f;
	if (argc < 2 || argc > 4)
	{
		std::cout << "Wrong number of arguments !" << std::endl;
		return (1);
	}
	f.open(argv[1], std::fstream::in);
	if (!f)
	{
		std::cout << "Error opening the file !" << std::endl;
		return (1);
	}
	/*   TO DO LIST
	Create a file called argv[1].replace
	Buscar en cada string una ocurrence de s1 y cambiarla por su similar de s2
	Handle error if s1 len != s2 len ????
	*/
	return (0);
}