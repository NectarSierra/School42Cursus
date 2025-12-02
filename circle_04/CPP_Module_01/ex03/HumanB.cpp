/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:00:04 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 09:18:29 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
#include "Weapon.h"

HumanB::HumanB(std::string name) : name(name)
{
    this->weapon_ptr = NULL;
}


void HumanB::attack()
{
    if (this->weapon_ptr)
        std::cout << this->name << " attacks with their " << this->weapon_ptr->getType() << std::endl;
    else
        std::cerr << "[ERROR] " << this->name << " has no weapon attributed." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon_ptr = &weapon;
}