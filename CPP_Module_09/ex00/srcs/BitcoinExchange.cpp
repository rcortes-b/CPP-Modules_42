#include "../includes/BitcoinExchange.hpp"

static void	ft_iterspace(std::string line, unsigned int &i)
{
	for (; std::isspace(line[i]);)
		i++;
}

static bool	ocurrence_date_aux(t_data &data, std::string &line, unsigned int &i, iterator &it, int db_it)
{
	unsigned int	value = 0;
	unsigned int	tmp = 0;

	value = ((line[i] - '0') * 10) + (line[i + 1] - '0');
	while (std::strncmp(&it->first.c_str()[db_it], &line.c_str()[i], 2))
	{
		tmp = ((it->first.c_str()[db_it] - '0') * 10) + (it->first.c_str()[db_it + 1] - '0');
		if (tmp > value)
		{
			it--;
			break ;
		}
		it++;
		if (it == data.data.end())
		{
			if (db_it == 5)
				std::cerr << "Error: month is out of range." << std::endl;
			else
				std::cerr << "Error: day is out of range." << std::endl;
			return (false);
		}
	}
	return (true);
}

static bool	check_data(std::string &line, unsigned int &i, unsigned int &tmp)
{
	unsigned int	temp_value = 0;
	if (DATE_SIZE - i != 10)
		return (false);
	for (tmp = i + 4; i < tmp; i++)
	{
		if (!std::isdigit(line[i]))
			return (false);
	}
	if (line[i] != '-')
		return (false);
	else
		i++;
	for (unsigned int l = 0; l < 2; l++)
	{
		for (tmp = i + 2; i < tmp; i++)
		{
			if (!std::isdigit(line[i]))
				return (false);
		}
		if (line[i] == '-' && !l)
			i++;
		temp_value = std::atoi(&line[i - 2]);
		if (!temp_value || (!l && temp_value > 12) || (l && temp_value > 31))
			return (false);
	}
	return (true);
}

static unsigned int	check_input(std::string &line)
{
	unsigned int	i = 0;
	unsigned int	tmp = 0;

	ft_iterspace(line, i);
	if (!check_data(line, i, tmp))
		return (INVALID_DATE);
	ft_iterspace(line, i);
	if (line[i] != '|')
		return (BAD_INPUT);
	i++;
	ft_iterspace(line, i);
	if (line[i] == '-')
		return (NEG_NUMBER);
	else
	{
		if (std::atof(&line.c_str()[i]) > 1000)
			return (LARGE_NUMBER);
	}
	while (line[i] != '\n' && line[i])
	{
		if (!std::isdigit(line[i]) && line[i] != '.')
			return (BAD_INPUT);
		i++;
	}
	return (0);
}

static void	check_ocurrence_date(t_data &data, std::string &line)
{
	iterator	it = data.data.begin();
	unsigned int	i = 0;

	ft_iterspace(line, i);
	while (std::strncmp(it->first.c_str(), &line.c_str()[i], 4))
	{
		it++;
		if (it == data.data.end())
		{
			std::cerr << "Error: year is out of range." << std::endl;
			return ;
		}
	}
	i += 5;
	if (!ocurrence_date_aux(data, line, i, it, 5))
		return ;
	i += 3;
	if (!ocurrence_date_aux(data, line, i, it, 8))
		return ;
	i += 2;
	while (!std::isdigit(line[i]))
		i++;

	unsigned int	i_date = 0;
	ft_iterspace(line, i_date);
	std::cout << line.substr(i_date, DATE_SIZE) << " => " << std::atof(&line.c_str()[i]);
	std::cout << " = " << it->second * std::atof(&line.c_str()[i]) << std::endl;

}

void	handle_output(t_data &data, std::string &line, int error_code)
{
	unsigned int	i = 0;
	switch (error_code)
	{ 
		case 1:
				std::cerr << "Error: bad input => ";
				ft_iterspace(line, i);
				std::cerr << line.substr(i, i + DATE_SIZE) << std::endl;
				break ;
		case 2:
				std::cerr << "Error: date format is invalid." << std::endl;
				break ;
		case 3:
				std::cerr << "Error: not a positive number." << std::endl;
				break;
		case 4:
				std::cerr << "Error: too large number." << std::endl;
				break;
		default:
				check_ocurrence_date(data, line);

	}
}

void	exchange_rate(t_data &data)
{
	std::string		line;
	unsigned int	err_code = 0;

	//Skip the first line, no values
	std::getline(data.input, line);

	while(std::getline(data.input, line))
	{
		err_code = check_input(line);
		handle_output(data, line, err_code);
	}
}