/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 10:01:33 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/20 16:00:35 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


# include <cctype>
# include <iomanip>
# include <iostream>
# include <limits>
# include "Contacts.hpp"

#define CONTACT_NUM 2

class PhoneBook
{
  private:
	Contacts contacts[CONTACT_NUM];
	int numContacts;

  public:
	PhoneBook();
	~PhoneBook();
	void addPhoneBookContact(std::string first_name, std::string last_name,
		std::string nickname, std::string darkest_secret, std::string number);
	Contacts getPhoneBookContact(int index);
	int getNumContacts()
	{
		return (numContacts);
	}
};

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
		contacts[CONTACT_NUM - 1].SetContact(first_name, last_name, nickname, number,
			darkest_secret);
	}
}

PhoneBook::~PhoneBook()
{
}
#endif