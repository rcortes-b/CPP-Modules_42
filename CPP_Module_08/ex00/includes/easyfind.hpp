#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NumberNotFound : public std::exception {
	public:
		const char	*what() const throw() {
			return ("The ocurrence hasn't been found in the container");
		}
};

template <typename T>

void	easyfind(T &array, int ocurrence)
{
	if (std::find(array.begin(), array.end(), ocurrence) != array.end())
	{
		std::cout << "The number " << ocurrence;
		std::cout << " has been found in the container" << std::endl;
	}
	else
		throw NumberNotFound();
}

/*void	easyfind(T &array, int ocurrence)
{
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++) {
		if (*it == ocurrence)
		{
			std::cout << "The number " << ocurrence;
			std::cout << " has been found in the container" << std::endl;
 			return ;
		}
	}
	throw NumberNotFound();
}*/

#endif