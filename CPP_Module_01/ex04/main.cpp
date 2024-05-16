/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:03:17 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:03:18 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

static void	fill_file(std::fstream &old_file, std::ofstream &new_file, std::string s1, std::string s2)
{
	std::string	line;
	size_t		found = 0;
	int			i = 0, l = 0;
	int			trigger = 0;
	int			is_first = 1;
	while (std::getline(old_file, line))
	{
		if (!is_first)
			new_file << std::endl;
		is_first = 0;
		trigger = 0;
		for (i = 0; line[i]; i++)
		{
			found = line.find(s1, i);
			if (found == std::string::npos)
				trigger = 1;
			if (!trigger && found == (size_t)i)
			{
				i += s1.size() - 1;
				for (l = 0; s2[l]; l++)
					new_file << s2[l];
			}
			else if (line[i])
				new_file << line[i];
		}
	}
}

int main(int argc, char **argv)
{
	std::fstream	f;
	std::string		new_str = "";
	std::string		file_format = ".replace";

	if (argc != 4 || !*argv[2])
	{
		std::cout << "Wrong number of arguments or invalid input!" << std::endl;
		return (1);
	}
	f.open(argv[1], std::fstream::in);
	if (!f)
	{
		std::cout << "Error opening the file !" << std::endl;
		return (1);
	}
	new_str = argv[1] + file_format;
	std::ofstream	new_file (new_str);
	fill_file(f, new_file, (std::string)argv[2], (std::string)argv[3]);
	return (0);
}
