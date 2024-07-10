#include "includes/BitcoinExchange.hpp"

static bool	error_handler(int argc, char **argv, t_data &data)
{
	if (argc != 2 || !argv[1] || !*argv[1])
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return (false);
	}


	data.input.open(argv[1], std::fstream::in);
	if (!data.input.is_open())
	{
		std::cerr << "Error: File does not exist or you don't have permission" << std::endl;
		return (false);
	}
	data.db.open("data.csv", std::fstream::in);
	if (!data.db.is_open())
	{
		std::cerr << "Error: Database does not exist or you don't have permission" << std::endl;
		return (false);
	}
	return (true);
}

static void	parse_database(t_data &data)
{
	std::string		line = "";
	
	//Skip the first line, no values
	std::getline(data.db, line);

	while (std::getline(data.db, line))
		data.data[line.substr(0, TRIMMER)] = static_cast<float>(std::atoi(line.c_str() + TRIMMER + 1));
}

int main(int argc, char **argv)
{
	t_data	data;

	if (!error_handler(argc, argv, data))
		return (1);
	parse_database(data);
	exchange_rate(data);
	return (0);
}