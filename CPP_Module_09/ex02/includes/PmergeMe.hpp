#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <stdbool.h>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
void	swap(T &a, T &b)
{
	if (a <= b)
		return ;

	T	tmp;

	tmp = b;
	b = a;
	a = tmp;
}

typedef std::vector<int> vector;
typedef std::list<int> list;
typedef std::vector<int>::iterator it_vec;
typedef std::list<int>::iterator it_list;

typedef struct s_merge
{
	list	nums;
	list	sorted;
	int		**values;
	size_t	pairs;
	bool	is_odd;
}				t_merge;

void	create_pairs(t_merge &data, int argc);
void	delete_values(t_merge &data);

#endif