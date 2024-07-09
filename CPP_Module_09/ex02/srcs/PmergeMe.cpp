#include "../includes/PmergeMe.hpp"

static void	sort_great_pairs(t_merge &data) //creo que aqui hay un error 
{
	size_t	tmp_pairs = data.pairs;
	int		*tmp = NULL;

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
	it_vec			it = data.nums.begin();

	data.pairs = ((argc - 1) / 2) + ((argc - 1) % 2);
	data.values = new int*[data.pairs + 1];
	data.values[data.pairs] = NULL;
	for (size_t i = 0; i < data.pairs; i++)
	{
		data.values[i] = new int[3];
		data.values[i][2] = 0;
		for (size_t j = 0; j < 2; j++)
		{
			data.values[i][j] = *it;
			it++;
			if (data.is_odd && i + 1 == data.pairs)
				break ;
		}
		if (!(data.is_odd && i + 1 == data.pairs))
			swap(data.values[i][0], data.values[i][1]);
	}
	sort_great_pairs(data);
}

static void	fill_temparrays(t_merge &data, int *tmp, int *res)
{
	for (size_t l = 0; l < data.pairs - data.is_odd; l++)
	{
		tmp[l] = data.values[l][0];
		res[l] = data.values[l][1];
	}
	if (data.is_odd)
		tmp[data.pairs - 1] = data.values[data.pairs - 1][0];
}

static void	insert_value_into_array(int *res, int value, int index, int max_len)
{
	int copy[max_len];

	for (int l = 0; l < max_len; l++)
		copy[l] = res[l];
	res[index] = value;
	index++;
	for (int j = index - 1; j < max_len; j++)
	{
		if (j + 1 != max_len)
			res[index] = copy[j];
		index++;
	}
}

void	insertion_sort(t_merge &data, int argc)
{
	int *res = new int[argc];
	int	tmp[data.pairs];
	
	res[argc - 1] = 0;
	fill_temparrays(data, tmp, res);
	unsigned int 	supp = 0;
	size_t			i = 0;
	for (; i < data.pairs; i++)
	{
		for (size_t j = 0; j < data.pairs - data.is_odd + supp; j++)
		{

			if ((!j && tmp[i] <= res[j]) || (j && res[j - 1] <= tmp[i] && res[j] > tmp[i]))
			{
				insert_value_into_array(res, tmp[i], j, argc - 1);
				supp++;
				break ;
			}
		}
	}
	for (i = 0; (int)i < argc - 1; i++)
		data.sorted.push_back(res[i]);
	delete [] res;
}