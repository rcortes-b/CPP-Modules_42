#include "../includes/PmergeMe.hpp"

void	push_tonewlist(t_merge &data)
{
	for (size_t i = 0; i < data.pairs; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			if (j == 1 && data.is_odd && i == data.pairs -1)
				return ;
			data.sorted.push_back(data.values[i][j]);
		}
	}
}

static void	sort_great_pairs(t_merge &data)
{
	int	*tmp = NULL;
	size_t	tmp_pairs = data.pairs;

	if (data.is_odd)
		tmp_pairs -= 1;
	for (size_t i = 0; i < tmp_pairs - 1; i++)
	{
		for (size_t j = i + 1; j < tmp_pairs; j++)
		{
			if (data.values[i][1] > data.values[j][1])
			{
				tmp = data.values[j];
				data.values[j] = data.values[i];
				data.values[i] = tmp;
			}
		}
	}
}

void	create_pairs(t_merge &data, int argc)
{
	it_list			it = data.nums.begin();

	data.pairs = ((argc - 1) / 2) + ((argc - 1) % 2);
	data.values = new int*[data.pairs];
	for (size_t i = 0; i < data.pairs; i++)
	{
		data.values[i] = new int[2];
		for (size_t j = 0; j < 2; j++)
		{
			data.values[i][j] = *it;
			it++;
			if (i == data.pairs - 1 && data.is_odd)
				break ;
		}
		if (!(i == data.pairs - 1 && data.is_odd))
			swap(data.values[i][0], data.values[i][1]);
		/*data.sorted.push_back(data.values[i][0]); //delete pq no quiero poner nada aun en el sorted
		if (!(i == data.pairs - 1 && data.is_odd)) //del
			data.sorted.push_back(data.values[i][1]); //del*/
	}
	sort_great_pairs(data);
	push_tonewlist(data);
}
