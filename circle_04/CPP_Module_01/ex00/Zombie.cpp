/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:14:58 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 18:16:50 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "[Debug] Constructor called for: " << this->name << std::endl;
}
Zombie::~Zombie()
{
	std::cout << "[Debug] Destructor called for: " << this->name << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}