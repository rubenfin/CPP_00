/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 10:01:33 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/19 16:20:15 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP	
#define PHONEBOOK_HPP

#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include "Contacts.hpp"

class PhoneBook
{
  private:
	Contacts contacts[8];
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

void PhoneBook::addPhoneBookContact(std::string first_name, std::string last_name,
	std::string nickname, std::string number, std::string darkest_secret)
{
	if (numContacts < 8)
	{
		contacts[numContacts].SetContact(first_name, last_name, nickname,
			number, darkest_secret);
		numContacts++;
	}
	else
	{
		numContacts = 0;
		PhoneBook::addPhoneBookContact(first_name, last_name, nickname,
			number, darkest_secret);
	}
}

PhoneBook::~PhoneBook()
{
}
#endif