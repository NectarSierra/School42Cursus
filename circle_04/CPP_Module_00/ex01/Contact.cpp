/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:57:05 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/03 08:24:47 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Contact.h"

bool Contact::isSet()
{
	return is_set;
}

std::string Contact::get_firstname()
{
	return firstname;
}
std::string Contact::get_lastname()
{
	return lastname;
}
std::string Contact::get_nickname()
{
	return nickname;
}
std::string Contact::get_phonenumber()
{
	return phonenumber;
}
std::string Contact::get_darkestsecret()
{
	return darkestsecret;
}

void Contact::fill_form()
{
	force_fill(firstname, "Firstname");
	if (std::cin.eof())
		return ;
	force_fill(lastname, "Lastname");
	if (std::cin.eof())
		return ;
	force_fill(nickname, "Nickname");
	if (std::cin.eof())
		return ;
	force_fill(phonenumber, "Phonenumber");
	if (std::cin.eof())
		return ;
	force_fill(darkestsecret, "Darkest secret");
	if (std::cin.eof())
		return ;
	is_set = true;
}

void Contact::force_fill(std::string& obj_var,const std::string& name)
{
	while (obj_var.empty())
	{
		std::cout << name << ": ";
		getline(std::cin, obj_var);
		if (std::cin.eof())
			break;
		if (obj_var.empty())
			std::cout << "\033[31mThis field cannot be empty, please try again.\033[0m" << std::endl;
	}
}