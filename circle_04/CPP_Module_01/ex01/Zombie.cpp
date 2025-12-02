/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:20:08 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 18:24:15 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie()
{
	std::cout << "[Debug] Constructor called for: " << this->name << std::endl;
}
Zombie::~Zombie()
{
	std::cout << "[Debug] Destructor called for: " << this->name << std::endl;
}

void Zombie::set_name( std::string rname )
{
	Zombie::name = rname;
}

void Zombie::announce( void )
{
	std::cout << name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}