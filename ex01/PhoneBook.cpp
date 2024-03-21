/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 11:47:09 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/21 12:28:24 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : numContacts(0)
{
}

Contacts PhoneBook::getPhoneBookContact(int index)
{
	if (index >= 0 && index < numContacts)
	{
		return (contacts[index]);
	}
	else
		return (Contacts());
}
int PhoneBook::getNumContacts(void)
{
	return (numContacts);
}

void PhoneBook::addPhoneBookContact(std::string first_name,
	std::string last_name, std::string nickname, std::string number,
	std::string darkest_secret)
{
	if (numContacts < CONTACT_NUM)
	{
		contacts[numContacts].SetContact(first_name, last_name, nickname,
			number, darkest_secret);
		numContacts++;
	}
	else
	{
		for (int i = 0; i < CONTACT_NUM - 1; ++i)
		{
			contacts[i] = contacts[i + 1];
		}
		contacts[CONTACT_NUM - 1].SetContact(first_name, last_name, nickname,
			number, darkest_secret);
	}
}

PhoneBook::~PhoneBook()
{
}
