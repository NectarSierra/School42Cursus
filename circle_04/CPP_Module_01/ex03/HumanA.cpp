/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:53:19 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/03 20:15:45 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include "Weapon.h"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon_ref(weapon){};

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon_ref.getType() << std::endl;
}