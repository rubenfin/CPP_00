/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contacts.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 15:49:39 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/20 16:00:07 by rfinneru      ########   odam.nl         */
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
	std::string getFirstName() const
	{
		return (first_name);
	}
		std::string getLastName() const
	{
		return (last_name);
	}
		std::string getNickName() const
	{
		return (nickname);
	}
	std::string getNum() const
	{
		return (number);
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

Contacts::Contacts()
{
}

Contacts::~Contacts()
{
}
#endif