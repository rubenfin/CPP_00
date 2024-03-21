/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 13:15:55 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/21 13:15:57 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string moreThan10(std::string &str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += '.';
	}
	return (str);
}

void	removeZeros(std::string &column)
{
	int	i;

	i = 0;
	while (column[i] == '0')
		i++;
	column.erase(0, i);
}

bool	findOnlySpace(const std::string &str)
{
	std::string::const_iterator iterator = str.begin();
	while (iterator != str.end() && std::isspace(*iterator))
		iterator++;
	return (!str.empty() && iterator == str.end());
}

bool	findNum(const std::string &str)
{
	std::string::const_iterator iterator = str.begin();
	while (iterator != str.end() && std::isalpha(*iterator))
		iterator++;
	return (!str.empty() && iterator == str.end());
}

bool	findChar(const std::string &str)
{
	std::string::const_iterator iterator = str.begin();
	while (iterator != str.end() && std::isdigit(*iterator))
		++iterator;
	return (!str.empty() && iterator == str.end());
}