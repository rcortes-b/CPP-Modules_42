#include "includes/PmergeMe.hpp"

void	delete_values(t_merge &data)
{
	for (size_t l = 0; l < data.pairs; l++)
		delete [] data.values[l];
	delete [] data.values;
}

static void	print_list(list &nums, bool is_before)
{
	if (is_before)
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (it_list it = nums.begin(); it != nums.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static bool	check_number(char *arg, unsigned int &j)
{
	unsigned int	tmp = j;
	unsigned int	zero_counter = 0;

	for (; arg[j] && arg[j] == '0' ;)
		zero_counter++;
	for (; arg[j] && !std::isspace(arg[j]);)
		j++;
	if (j - tmp - zero_counter > 10)
		return (false);
	if (!arg[j])
		j--;
	return (true);
}

static bool	check_input(int argc, char **argv, list &nums)
{
	unsigned int	num = 0;
	if (argc < 3)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return (false);
	}
	for (unsigned int i = 0; argv[i]; i++)
	{
		for (unsigned int j = 0; argv[i][j]; j++)
		{
			num = std::atoi(argv[i]);
			if (std::isdigit(argv[i][j]))
			{
				if (!check_number(argv[i], j) || num > 2147483647)
				{
					std::cerr << "Error: number is too big" << std::endl;	
					return (false);
				}
			}
			else if (!std::isspace(argv[i][j]))
			{
				std::cerr << "Error: there is a negative number or an undefined character" << std::endl;
				return (false);
			}
		}
		nums.push_back(num);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_merge	data;

	if (!check_input(argc, &argv[1], data.nums))
		return (1);
	print_list(data.nums, true);
	data.is_odd = 0;
	if ((argc - 1 % 2) != 0)
		data.is_odd = 1;
	create_pairs(data, argc);
	print_list(data.sorted, false);
	delete_values(data);
	return (0);
}