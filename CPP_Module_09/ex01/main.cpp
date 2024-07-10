#include "includes/RPN.hpp"

unsigned int	is_operator(char c)
{
	unsigned int	op = 0;

	switch (c)
	{
		case '+':
				op = 1;
				break ;
		case '-':
				op = 2;
				break ;
		case '*':
				op = 3;
				break ;
		case '/':
				op = 4;
				break ;
		default:
				op = 0;
	}
	return (op);
}

static bool	check_input(int argc, char **argv)
{
	unsigned int i = 0;

	if (argc != 2 || !argv[1] || !*argv[1])
	{
		std::cerr << "Invalid number of arguments or argument is invalid." << std::endl;
		return (false);
	}
	for (; argv[1][i]; i++)
	{
		if (!std::isdigit(argv[1][i]) && !std::isspace(argv[1][i])
			&& !is_operator(argv[1][i]))
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
		else if (std::isdigit(argv[1][i]) && std::isdigit(argv[1][i + 1]))
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
	}
	for (i = 0; std::isspace(argv[1][i]);)
		i++;
	if (is_operator(argv[1][i]) && std::isspace(argv[1][i + 1]))
	{
		std::cerr << "Error" << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	std::vector<char>	operators;

	operators.push_back('+');
	operators.push_back('-');
	operators.push_back('*');
	operators.push_back('/');

	if (!check_input(argc, argv))
		return (1);

	stack	nums;

	if (!calculate_RPN(nums, argv[1]))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}
