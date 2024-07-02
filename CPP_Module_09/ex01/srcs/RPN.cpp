#include "../includes/RPN.hpp"

static int	do_operation(unsigned int op, int value1, int value2)
{
	switch (op)
	{
		case 1:
				return (value1 + value2);
		case 2:
				return (value1 - value2);
		case 3:
				return (value1 * value2);
		case 4:
				return (value1 / value2);
	}
	return (0);
}

bool	calculate_RPN(stack &nums, char *input)
{
	int	tmp = 0;
	int	res = 0;

	for (unsigned int i = 0; input[i]; i++)
	{
		if (std::isdigit(input[i]))
			nums.push(input[i] - '0');
		else if (is_operator(input[i]) && (!input[i + 1] || std::isspace(input[i + 1])))
		{
			if (nums.size() < 2)
				return (false);
			tmp = nums.top();
			nums.pop();
			res = do_operation(is_operator(input[i]), nums.top(), tmp);
			nums.pop();
			nums.push(res);
		}
	}
	if (nums.size() > 1)
		return (false);
	std::cout << res << std::endl;
	return (true);
}