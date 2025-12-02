/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:08:08 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/24 10:29:27 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

int main( void )
{
	DiamondTrap* a = new DiamondTrap("A");
	a->attack("b");
	a->beRepaired(10);
	a->guardGate();
	a->highFivesGuys();
	a->whoAmI();
	delete a;

	DiamondTrap* b = new DiamondTrap("A");
	b->whoAmI();
	delete b;
	
	return (0);
}