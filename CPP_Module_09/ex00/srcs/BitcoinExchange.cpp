#include "../includes/BitcoinExchange.hpp"

static void	ft_iterspace(std::string line, unsigned int &i)
{
	for (; std::isspace(line[i]);)
		i++;
}

static bool	check_data(std::string &line, unsigned int &i, unsigned int &tmp)
{
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
	std::map<std::string, float>::iterator	it = data.data.begin();
	unsigned int	i = 0;
	unsigned int	value = 0;
	unsigned int	tmp = 0;

	ft_iterspace(line, i);
	while (std::strncmp(it->first.c_str(), &line.c_str()[i], 4))
		it++;
	i += 5;
	value = ((line[i] - '0') * 10) + (line[i + 1] - '0');
	while (std::strncmp(&it->first.c_str()[5], &line.c_str()[i], 2))
	{
		
		tmp = ((it->first.c_str()[5] - '0') * 10) + (it->first.c_str()[6] - '0');
		if (tmp > value)
		{
			it--;
			break ;
		}
		it++;
	}
	i += 3;
	value = ((line[i] - '0') * 10) + (line[i + 1] - '0');
	while (std::strncmp(&it->first.c_str()[8], &line.c_str()[i], 2))
	{
		tmp = ((it->first.c_str()[8] - '0') * 10) + (it->first.c_str()[9] - '0');
		if (tmp > value)
		{
			it--;
			break ;
		}
		it++;
	}
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
				std::cout << "Error: bad input => ";
				ft_iterspace(line, i);
				std::cout << line.substr(i, i + DATE_SIZE) << std::endl;
				break ;
		case 2:
				std::cout << "Error: date format is invalid." << std::endl;
				break ;
		case 3:
				std::cout << "Error: not a positive number." << std::endl;
				break;
		case 4:
				std::cout << "Error: too large number." << std::endl;
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