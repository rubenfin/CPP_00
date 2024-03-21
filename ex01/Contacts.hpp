/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contacts.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 15:49:39 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/21 13:28:25 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include "PhoneBook.hpp"
# include <cctype>
# include <iomanip>
# include <iostream>
# include <limits>

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
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getNum() const;
	std::string getSecret() const;
};

#endif