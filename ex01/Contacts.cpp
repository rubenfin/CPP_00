/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contacts.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 10:56:05 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/21 11:48:59 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contacts::Contacts()
{
}

Contacts::~Contacts()
{
}

void Contacts::SetContact(std::string first_name, std::string last_name,
	std::string nickname, std::string number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->number = number;
	this->darkest_secret = darkest_secret;
}

std::string Contacts::getFirstName() const
{
	return (first_name);
}

std::string Contacts::getLastName() const
{
	return (last_name);
}

std::string Contacts::getNickName() const
{
	return (nickname);
}

std::string Contacts::getNum() const
{
	return (number);
}

std::string Contacts::getSecret() const
{
	return (darkest_secret);
}