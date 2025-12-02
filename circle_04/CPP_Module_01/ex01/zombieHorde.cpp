/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:20:49 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 18:25:04 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name )
{
	int i = 0;
	Zombie *zombie_horde = new Zombie[N];
	while (i < N)
	{
		zombie_horde[i].set_name(name);
		std::cout << "[Debug] " << i << " ";
		zombie_horde[i].announce();
		i++;
	}
	return &zombie_horde[0];
}