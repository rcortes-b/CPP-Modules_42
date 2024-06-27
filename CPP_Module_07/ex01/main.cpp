#include "includes/iter.hpp"
template <typename T>
T	sum1(T& a)
{
	a += 1;
	return (a);
}

int main(void)
{
	int nums[5] = {1, 2, 3, 4, 5};
	//Iter not applied
	for (int i = 0; i < 5; i++)
	{
		std::cout << "num: " << nums[i] << std::endl;
	}
	std::cout << std::endl;
	iter(nums, 5, sum1);
	//Iter applied
	for (int i = 0; i < 5; i++)
	{
		std::cout << "num: " << nums[i] << std::endl;
	}
	std::cout << std::endl;
/*///////////////////////////////////////////////////////*/
	char letters[4] = {'h', 'o', 'l', 'a'};
	//Iter not applied
	for (int i = 0; i < 4; i++)
	{
		std::cout << "letter: " << letters[i] << std::endl;
	}
	std::cout << std::endl;
	iter(letters, 4, sum1);
	//Iter applied
	for (int i = 0; i < 4; i++)
	{
		std::cout << "letter: " << letters[i] << std::endl;
	}
	std::cout << std::endl;

	return (0);
}