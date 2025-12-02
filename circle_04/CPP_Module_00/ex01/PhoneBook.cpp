/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:59:58 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/03 08:17:33 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

std::string PhoneBook::truncate(std::string str, size_t width)
{
    if (str.length() > width)
        return str.substr(0, width) + ".";
    return str;
}

void PhoneBook::push_to_phonebook(PhoneBook& phonebookobj, int PhoneBookLimit)
{
	int i;

	i = 0;
	while (i < PhoneBookLimit - 1)
	{
		phonebookobj.contacts[i] = phonebookobj.contacts[i + 1];
		i++;
	}
}

void PhoneBook::add_to_phonebook(PhoneBook& phonebookobj, int PhoneBookLimit, Contact contactobj)
{
	int i;

	i = 0;
	while (phonebookobj.contacts[i].isSet() == true)
		i++;
	if (i == PhoneBookLimit)
	{
		push_to_phonebook(phonebookobj, PhoneBookLimit);
		phonebookobj.contacts[i - 1] = contactobj;
		std::cout << "\033[0;33mPhone book was full the least recent contact has been removed.\033[0;0m" << std::endl;
	}
	else
	{
		phonebookobj.contacts[i] = contactobj;
		std::cout << "\033[32mContact successfully registered!\033[0m" << std::endl;
	}
}

void PhoneBook::print_phonebook(PhoneBook& phonebookobj, int PhoneBookLimit)
{
	int index, i;
	std::string	user_input;

	std::cout << "\e[90m";
	std::cout << "|";
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRSTNAME" << "|";
	std::cout << std::setw(10) << "LASTNAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|" << std::endl;
	std::cout << "|----------+----------+----------+----------|" << std::endl;
	i = 0;
	while (i < PhoneBookLimit && phonebookobj.contacts[i].isSet())
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << phonebookobj.truncate(phonebookobj.contacts[i].get_firstname(), 9) << "|";
		std::cout << std::setw(10) << phonebookobj.truncate(phonebookobj.contacts[i].get_lastname(), 9) << "|";
		std::cout << std::setw(10) << phonebookobj.truncate(phonebookobj.contacts[i].get_nickname(), 9) << "|" << std::endl;
		i++;
	}
	std::cout << "\e[0m" << std::endl << "Search index: ";
	getline(std::cin, user_input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::clearerr(stdin);
		std::cin.clear();
		return;
	}
	index = user_input[0] - '0' - 1;
	if (((char)index >= 0 && (char)index <= 8) && phonebookobj.contacts[index].isSet() == true && user_input.length() == 1)
	{
		std::cout << std::endl;
		std::cout << "Firstname: " << phonebookobj.contacts[index].get_firstname() << std::endl;
		std::cout << "Lastname: " << phonebookobj.contacts[index].get_lastname() << std::endl;
		std::cout << "Nickname: " << phonebookobj.contacts[index].get_nickname() << std::endl;
		std::cout << "Phonenumber: " << phonebookobj.contacts[index].get_phonenumber() << std::endl;
		std::cout << "Darkestsecret: " << phonebookobj.contacts[index].get_darkestsecret() << std::endl;
	}
	else
		std::cout << "\e[31mThis index contact doesn't exit.\e[0m" << std::endl;
}