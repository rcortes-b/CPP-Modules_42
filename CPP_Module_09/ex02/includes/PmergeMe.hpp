#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <stdbool.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <time.h>
#include <typeinfo>

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
typedef std::deque<int> deque;
typedef std::vector<int>::iterator it_vec;
typedef std::deque<int>::iterator it_deq;

typedef struct s_merge
{
	vector	vecNums;
	vector	vecSorted;
	deque	decNums;
	deque	deqSorted;
	int		**values;
	size_t	pairs;
	bool	is_odd;
	clock_t	vecStart, vecEnd;
	clock_t	deqStart, deqEnd;
}				t_merge;

void	create_pairs(t_merge &data, int argc);
void	delete_values(t_merge &data);
void	insertion_sort(t_merge &data, int argc);
void	insertion_sort_deque(t_merge &data, int argc);

#endif