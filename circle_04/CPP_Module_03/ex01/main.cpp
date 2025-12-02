/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:08:08 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/23 13:09:37 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

int main( void )
{
	ScavTrap* a = new ScavTrap("Mickeal");
	delete a;

	std::cout << std::endl;
	
	ScavTrap* b = new ScavTrap("Jackson");
	b->attack("TEST");
	b->guardGate();
	b->beRepaired(100);
	b->takeDamage(20);
	b->takeDamage(20);
	b->takeDamage(20);
	b->takeDamage(20);
	b->takeDamage(20);
	b->takeDamage(20);
	b->takeDamage(20);
	b->takeDamage(20);
	b->takeDamage(20);
	b->takeDamage(20);
	b->takeDamage(20);
	
	b->beRepaired(100);
	b->attack("TEST");
	delete b;

	std::cout << std::endl;
	
	ScavTrap* c = new ScavTrap("Jackson");
	c->attack("TEST");
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(100);
	c->beRepaired(UINT_MAX);
	delete c;
	
	return (0);
}