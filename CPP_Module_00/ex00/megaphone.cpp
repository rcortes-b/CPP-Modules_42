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

//std::cout << "The value of x is: " << x << std::endl;

#include <iostream>

static void	iterate_space(char *str, int *index)
{
	while (str[*index] == ' ' || str[*index] == '\t')
		(*index)++;
}

static int	is_lastchr(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int j = 1; argv[j]; j++)
	{
		for (int i = 0; argv[j][i]; i++)
		{
			if (i == 0)
				iterate_space(argv[j], &i);
			if (is_lastchr(&argv[j][i]))
				break ;
			if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
				argv[j][i] -= 32;
			std::cout << argv[j][i];
		}
		if (argv[j + 1])
			std::cout << " ";
	}
	std::cout << std::endl;
}
