/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 09:39:30 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/18 17:08:18 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			for (size_t j = 0; av[i][j]; j++)
				std::cout << static_cast<char>(std::toupper(av[i][j]));
			std::cout << " ";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
