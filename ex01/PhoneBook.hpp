/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 10:01:33 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/18 17:19:59 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

class Contacts
{
  private:
	int ContactNumber;
	std::string ContactName;

  public:
	Contacts(void);
	~Contacts();
	void SetContact(int number, std::string name);
	Contacts GetContact(Contacts contacts);
	std::string GetName(std::string &name);
};
std::string GetName()
{
	return (ContactName);
}
void Contacts::SetContact(int number, std::string name)
{
	this->ContactNumber = number;
	this->ContactName = name;
}

Contacts Contacts::GetContact(Contacts contacts)
{
	return (contacts);
}

Contacts::Contacts() : ContactNumber(0), ContactName("")
{
}

Contacts::~Contacts()
{
}

class PhoneBook
{
  private:
	Contacts contacts[8];
	int numContacts;

  public:
	PhoneBook(void);
	~PhoneBook();
	void addPhoneBookContact(int number, std::string name);
	Contacts getPhoneBookContact(int index);
};

PhoneBook::PhoneBook(void)
{
	numContacts = 0;
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

void PhoneBook::addPhoneBookContact(int number, std::string name)
{
	if (this->numContacts < 8)
	{
		contacts[numContacts].SetContact(number, name);
		this->numContacts++;
	}
}

PhoneBook::~PhoneBook()
{
}
