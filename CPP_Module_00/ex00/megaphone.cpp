/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:05:40 by rcortes-          #+#    #+#             */
/*   Updated: 2024/04/14 16:05:42 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	iterate_space(char *str, int *i)
{
	while (std::isspace(str[*i]))
		(*i)++;	
}

static int	is_lastchr(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isspace(str[i]))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int j = 1; argv[j]; j++)
	{
		i = 0;
		iterate_space(argv[j], &i);
		while (argv[j][i] && !is_lastchr(&argv[j][i]))
		{
			if (i > 0 && std::isspace(argv[j][i]) && !std::isspace(argv[j][i - 1]))
				std::cout << " ";
			iterate_space(argv[j], &i);
			if (!argv[j][i])
				break ;
			std::cout << (char)std::toupper(argv[j][i]);
			i++;
		}
		if (argv[j + 1])
			std::cout << " ";
	}
	std::cout << std::endl;
}
