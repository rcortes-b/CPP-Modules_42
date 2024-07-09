#include "includes/PmergeMe.hpp"

void	delete_values(t_merge &data)
{
	for (size_t l = 0; l < data.pairs; l++)
		delete [] data.values[l];
	delete [] data.values;
}

static void	print_list(vector &vecNums, bool is_before)
{
	if (is_before)
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (it_vec it = vecNums.begin(); it != vecNums.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static bool	check_number(char *arg, unsigned int &j)
{
	unsigned int	tmp = j;
	unsigned int	zero_counter = 0;

	for (; arg[j] && arg[j] == '0' ;)
	{
		j++;
		zero_counter++;
	}
	for (; arg[j] && std::isdigit(arg[j]);)
	{
		j++;
	}
	if (arg[j] && !std::isdigit(arg[j]))
		return (false);
	else if (j - tmp - zero_counter > 10)
		return (false);
	if (!arg[j])
		j--;
	return (true);
}

static bool	check_input(int argc, char **argv, vector &vecNums)
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
				std::cout << "pq no etra" << std::endl;
				std::cerr << "Error: there is a negative number or an undefined character" << std::endl;
				return (false);
			}
		}
		vecNums.push_back(num);
	}
	return (true);
}

template <typename T>

static const char	*print_type(T type)
{
	if (typeid(type).name() == typeid(vector).name())
		return ("std::vector");
	else if (typeid(type).name() == typeid(deque).name())
		return ("std::deque");
	else
		return ("Unknown type");
}

int	main(int argc, char **argv)
{
	t_merge	data;

	if (!check_input(argc, &argv[1], data.vecNums))
		return (1);

	print_list(data.vecNums, true);

	data.is_odd = 0;
	if (((argc - 1) % 2) != 0)
		data.is_odd = 1;


	create_pairs(data, argc);
	data.vecStart = clock();
	insertion_sort(data, argc);
	data.deqStart = clock();
	insertion_sort_deque(data, argc);

	print_list(data.vecSorted, false);

	double dblTime = static_cast<double>(data.vecEnd - data.vecStart);
	std::cout << "Time to process a range of " << argc - 1 << " elements with ";
	std::cout << print_type(data.vecSorted) << " -> " << dblTime << " us" << std::endl;
	dblTime = static_cast<double>(data.deqEnd - data.deqStart);
	std::cout << "Time to process a range of " << argc - 1 << " elements with ";
	std::cout << print_type(data.deqSorted) << " -> " << dblTime << " us" << std::endl;

	delete_values(data);
	return (0);
}