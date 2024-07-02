#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <stdbool.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <iterator>

#define TRIMMER 10
#define DATE_SIZE 10

enum error_code
{
	BAD_INPUT = 1,
	INVALID_DATE,
	NEG_NUMBER,
	LARGE_NUMBER
};

typedef struct s_data
{
	std::ifstream					db;
	std::ifstream					input;
	std::map<std::string, float>	data;
}				t_data;


void			exchange_rate(t_data &data);

#endif