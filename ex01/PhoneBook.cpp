#include "PhoneBook.hpp"

void	DirectInput(PhoneBook *MyPhoneBook, std::string input)
{
	Contacts	contacts;
	int			num;

	std::string name;
	if (input == "ADD")
	{
		std::cout << "Name?" << std::endl;
		std::cin >> name;
		std::cout << "number?" << std::endl;
		std::cin >> num;
		(*MyPhoneBook).addPhoneBookContact(num, name);
	}
	else if (input == "SEARCH")
	{
		for (size_t i = 0; i < 8; i++)
		{
			contacts = (*MyPhoneBook).getPhoneBookContact(i);
			std::cout << contacts.getName() << "\n" << contacts.getNum() << "\n" << std::endl;
		}
	}
	else
		std::cout << "Wrong input, please try again!" << std::endl;
}

int	main(void)
{
	PhoneBook MyPhoneBook;
	std::string input;

	while (1)
	{
		std::cout << "Welcome to your PhoneBook!\nwould you like to ADD | SEARCH | EXIT" << std::endl;
		std::cin >> input;
		if (std::cin.eof() || input == "EXIT")
			break ;
		DirectInput(&MyPhoneBook, input);
		std::cin.clear();
		fflush(stdin);
	}

	return (0);
}