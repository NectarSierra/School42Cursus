/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:31:29 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 18:04:00 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl << std::endl;
}
void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}
void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}
void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;;
}

void Harl::complain(std::string level)
{
	std::string complains_type[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
    void (Harl::*complains[])(void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	int i = 0;
	while (level != complains_type[i] && i < 4)
		i++;
	while (1)
	{
		switch (i)
		{
			case 0:
				(this->*complains[0])();
				i++;
				break;
			case 1:
				(this->*complains[1])();
				i++;
				break;
			case 2:
				(this->*complains[2])();
				i++;
				break;
			case 3:
				(this->*complains[3])();
				return;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				return;
		}
	}
}