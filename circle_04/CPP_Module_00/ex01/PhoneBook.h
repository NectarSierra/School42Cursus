/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:58:17 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/03 08:17:43 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Contact.h"

class PhoneBook {
	private:
		std::string truncate(std::string str, size_t width);
		void push_to_phonebook(PhoneBook& phonebookobj, int PhoneBookLimit);
		Contact contacts[8];
	public:
		void add_to_phonebook(PhoneBook& phonebookobj, int PhoneBookLimit, Contact contactobj);
		void print_phonebook(PhoneBook& phonebookobj, int PhoneBookLimit);
};