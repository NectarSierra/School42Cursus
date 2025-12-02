/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:48:37 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/04 18:32:55 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.h"

class HumanB
{
	private:
		Weapon *weapon_ptr;
		std::string name;
	public:
		HumanB(std::string name);
        void attack();
        void setWeapon(Weapon &weapon);
};

#endif