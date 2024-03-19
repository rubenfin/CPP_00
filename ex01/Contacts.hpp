/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contacts.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 15:49:39 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/19 16:12:15 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include "PhoneBook.hpp"

class Contacts
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
	std::string number;

  public:
	Contacts(void);
	~Contacts();
	void SetContact(std::string first_name, std::string last_name,
	std::string nickname, std::string number, std::string darkest_secret);
	Contacts GetContact(Contacts contacts);
	std::string getNum() const
	{
		return (number);
	}
	std::string getName() const
	{
		return (first_name);
	}
};

void Contacts::SetContact(std::string first_name, std::string last_name,
	std::string nickname, std::string number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->number = number;
	this->darkest_secret = darkest_secret;
}

Contacts Contacts::GetContact(Contacts contacts)
{
	return (contacts);
}

Contacts::Contacts()
{
}

Contacts::~Contacts()
{
}
#endif