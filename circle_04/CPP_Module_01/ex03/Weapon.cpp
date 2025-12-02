/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:47:13 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/03 20:01:30 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(){};

Weapon::Weapon(std::string type)
{
	this->type = type;
}


void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string &Weapon::getType()
{
	return(this->type);
}