/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:14:27 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 18:14:29 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main( void )
{
	Zombie *test = newZombie("Zombie_1");
	randomChump("Zombie_2");
	delete test;
	return (0);
}