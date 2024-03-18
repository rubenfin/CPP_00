/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 10:01:22 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/18 17:19:45 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	DirectInput(PhoneBook MyPhoneBook, std::string input)
{
	int			num;
	Contacts	contacts;

	std::string name;
	if (input == "ADD")
	{
		std::cout << "Name?" << std::endl;
		std::cin >> name;
		std::cout << "number?" << std::endl;
		std::cin >> num;
		MyPhoneBook.addPhoneBookContact(num, name);
		for (size_t i = 0; i < 8; i++)
		{
            contacts = MyPhoneBook.getPhoneBookContact(i);
			std::cout << GetName(contacts) << std::endl;
		}
	}
	else if (input == "SEARCH")
	{
	}
	else if (input == "EXIT")
	{
	}
	else
		std::cout << "Wrong input, please try again!" << std::endl;
}

int	main(void)
{
	PhoneBook MyPhoneBook;
	std::string input;

	while (1)
	{
		std::cout << "Welcome to your PhoneBook!\nwould you like to ADD | SEARCH | EXIT" << std::endl;
		std::cin >> input;
		if (std::cin.eof())
			break ;
		DirectInput(MyPhoneBook, input);
		std::cin.clear();
		fflush(stdin);
	}

	return (0);
}