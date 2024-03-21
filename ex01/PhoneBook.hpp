/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 10:01:33 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/21 13:28:13 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contacts.hpp"
# include <cctype>
# include <iomanip>
# include <iostream>
# include <limits>
# define CONTACT_NUM 8

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
	int getNumContacts(void);
};

std::string moreThan10(std::string &str);
void	removeZeros(std::string &column);
bool	findOnlySpace(const std::string &str);
bool	findNum(const std::string &str);
bool	findChar(const std::string &str);

#endif