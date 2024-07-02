#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stdbool.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <iterator>

typedef std::stack<int>	stack;

bool			calculate_RPN(stack &nums, char *input);
unsigned int	is_operator(char c);

#endif