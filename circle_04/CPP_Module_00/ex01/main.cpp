/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:42:16 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/03 08:27:48 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

int main()
{
	std::string	user_input;
	PhoneBook	phonebookobj;
	int			PhoneBookLimit;

	PhoneBookLimit = 8;
	std::cout << "\033[0;33mWelcome to your personal Phone-Book, here is a list of commands you can type: ADD, SEARCH, EXIT.\033[0;0m" << std::endl;
	while (user_input != "\r")
	{
		std::cout << "> ";
		getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
		}
		else if (user_input == "ADD")
		{
			Contact contactobj;
			contactobj.fill_form();
			if (std::cin.eof())
			{
				std::clearerr(stdin);
				std::cout << std::endl << "\033[31mContact creation cancelled.\033[0m" << std::endl;
				std::cin.clear();
				continue ;
			}
			phonebookobj.add_to_phonebook(phonebookobj, PhoneBookLimit, contactobj);
		}
		else if (user_input == "SEARCH")
			phonebookobj.print_phonebook(phonebookobj, PhoneBookLimit);
		else if (user_input == "EXIT")
			break;
		else if (user_input == "")
			continue;
		else
			std::cout << "\033[31mThis command doesn't exist.\033[0m" << std::endl;
	}
	return (0);
}