#include "PhoneBook.hpp"

std::string moreThan10(std::string &str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += '.';
	}
	return (str);
}

void	removeZeros(std::string &column)
{
	int	i;

	i = 0;
	while (column[i] == '0')
		i++;
	column.erase(0, i);
}

bool	findNum(const std::string &str)
{
	std::string::const_iterator iterator = str.begin();
	while (iterator != str.end() && std::isalpha(*iterator))
		iterator++;
	return (!str.empty() && iterator == str.end());
}

bool	findChar(const std::string &str)
{
	std::string::const_iterator iterator = str.begin();
	while (iterator != str.end() && std::isdigit(*iterator))
		++iterator;
	return (!str.empty() && iterator == str.end());
}

void	printSingleUser(PhoneBook *MyPhoneBook, int numofcontacts)
{
	Contacts	contacts;
	int			column_int;

	std::string column;
	while (true && !std::cin.eof())
	{
		std::cout << "Which column would you like to see? 1 - 8\n";
		std::cin >> column;
		removeZeros(column);
		if (column.length() > 2 || !findChar(column))
		{
			std::cout << "This column doesn't exist!" << std::endl;
			continue ;
		}
		else
			column_int = std::stoi(column);
		contacts = (*MyPhoneBook).getPhoneBookContact(column_int - 1);
		if ((numofcontacts > column_int - 1) && (column_int >= 1
				&& column_int <= CONTACT_NUM))
		{
			std::cout << " - First name --> " << contacts.getFirstName() << "\n";
			std::cout << " - Last name  --> " << contacts.getLastName() << "\n";
			std::cout << " - Nickname   --> " << contacts.getNickName() << "\n";
			std::cout << " - Number     --> " << contacts.getNum() << "\n";
			break ;
		}
		else
			std::cout << "This column doesn't exist!" << std::endl;
	}
}

std::string getInputFromUser(std::string prompt, bool noChar, bool noNum)
{
	std::string input;
	while (true && !std::cin.eof())
	{
		std::cout << prompt << std::endl;
		std::cin >> input;
		if (std::cin.eof())
			return ("");
		if (noChar)
		{
			if (!findChar(input))
			{
				std::cout << "This field can not have any characters!" << std::endl;
				continue ;
			}
		}
		if (noNum)
		{
			if (!findNum(input))
			{
				std::cout << "This field can not have any numbers!" << std::endl;
				continue ;
			}
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break ;
	}
	return (input);
}

void	addContact(PhoneBook *MyPhoneBook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
	std::string number;
	while (!std::cin.eof())
	{
		first_name = getInputFromUser("First name:", false, true);
		last_name = getInputFromUser(first_name + "'s last name: ", false,
				true);
		nickname = getInputFromUser(first_name + "'s nickname: ", false, false);
		number = getInputFromUser(first_name + "'s number: ", true, false);
		darkest_secret = getInputFromUser(first_name + "'s darkest secret: ",
				false, false);
		(*MyPhoneBook).addPhoneBookContact(first_name, last_name, nickname,
			number, darkest_secret);
		if (std::cin.eof())
			break ;
		std::cout << first_name << " successfully added to phonebook "
					<< "[" << MyPhoneBook->getNumContacts() << "/8]" << std::endl;
		break ;
	}
}

void	doSearch(PhoneBook *MyPhoneBook)
{
	Contacts	contacts;
	int			numofcontacts;

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
	std::string number;
	numofcontacts = (*MyPhoneBook).getNumContacts();
	if (numofcontacts == 0)
	{
		std::cout << "No contacts available, please add one!" << std::endl;
		return ;
	}
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (size_t i = 0; i < CONTACT_NUM; i++)
	{
		contacts = (*MyPhoneBook).getPhoneBookContact(i);
		first_name = contacts.getFirstName();
		last_name = contacts.getLastName();
		nickname = contacts.getNickName();
		std::cout << "|" << std::setw(10) << std::right << i
			+ 1 << "|" << std::setw(10) << std::right << moreThan10(first_name) << "|" << std::setw(10) << std::right << moreThan10(last_name) << "|" << std::setw(10) << std::right << moreThan10(nickname) << "|" << std::endl;
	}
	std::cout << " ⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻ " << std::endl;
	printSingleUser(MyPhoneBook, numofcontacts);
}

void	DirectInput(PhoneBook *MyPhoneBook, std::string input)
{
	if (input == "ADD")
		addContact(MyPhoneBook);
	else if (input == "SEARCH")
		doSearch(MyPhoneBook);
	else if (input == "HELP")
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
	else
		std::cout << "Wrong input, please try again!" << std::endl;
}

int	main(void)
{
	PhoneBook MyPhoneBook;
	std::string input;
	std::cout << "Welcome to your PhoneBook!\nwould you like to ADD | SEARCH | EXIT" << std::endl;

	while (1)
	{
		std::cout << "~ PhoneBook $: ";
		std::cin >> input;
		if (std::cin.eof())
		{
			std::cout << "\n";
			break ;
		}
		if (input == "EXIT")
			break ;
		DirectInput(&MyPhoneBook, input);
	}
	std::cout << "You closed your PhoneBook,thanks for using and see you soon!" << std::endl;
	return (0);
}