#include "PhoneBook.hpp"

void	addContact(PhoneBook *MyPhoneBook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
	std::string number;
	while (!std::cin.eof())
	{
		std::cout << "First name:" << std::endl;
		std::cin >> first_name;
		std::cout << "Last name:" << std::endl;
		std::cin >> last_name;
		std::cout << "Nickname:" << std::endl;
		std::cin >> nickname;
		std::cout << "Number:" << std::endl;
		std::cin >> number;
		std::cout << "Darkest secret:" << std::endl;
		std::cin >> darkest_secret;
		(*MyPhoneBook).addPhoneBookContact(first_name, last_name, nickname,
			number, darkest_secret);
		break ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	doSearch(PhoneBook *MyPhoneBook)
{
	Contacts	contacts;
	int			numofcontacts;
	int			column;

	numofcontacts = (*MyPhoneBook).getNumContacts();
	if (numofcontacts == 0)
	{
		std::cout << "No contacts available, please add one!" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 8; i++)
	{
		contacts = (*MyPhoneBook).getPhoneBookContact(i);
		std::cout << contacts.getName() << "\n" << contacts.getNum() << "\n" << std::endl;
	}
	std::cout << "Which column would you like to see? 1 - 8";
	std::cin >> column;
	contacts = (*MyPhoneBook).getPhoneBookContact(column);
	if (contacts)
	{
		std::cout << contacts.getName() << "\n" << contacts.getNum() << "\n" << std::endl;
	}
}

void	DirectInput(PhoneBook *MyPhoneBook, std::string input)
{
	if (input == "ADD")
		addContact(MyPhoneBook);
	else if (input == "SEARCH")
		doSearch(MyPhoneBook);
	else if (input != "")
		std::cout << "Wrong input, please try again!" << std::endl;
}

int	main(void)
{
	PhoneBook MyPhoneBook;
	std::string input;
	std::cout << "Welcome to your PhoneBook!\nwould you like to ADD | SEARCH | EXIT" << std::endl;

	while (1)
	{
		std::cout << ">> PhoneBook $: ";
		std::cin >> input;
		if (std::cin.eof() || input == "EXIT")
			break ;
		DirectInput(&MyPhoneBook, input);
	}

	return (0);
}