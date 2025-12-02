/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 07:50:40 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/24 10:24:16 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

// Constructor( void | std::string ), copy construcor, destrucor;
DiamondTrap::DiamondTrap( void )
{
	std::cout << "[DiamondTrap] Default constructor called" << std::endl;
	this->name = "Undefined";
	ClapTrap::name = "Undefined_clap_name";
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_damage = FragTrap::Attack_damage;
}

DiamondTrap::DiamondTrap( std::string name )
{
	std::cout << "[DiamondTrap] Default constructor called" << std::endl;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_damage = FragTrap::Attack_damage;
}

DiamondTrap::DiamondTrap( const DiamondTrap& obj)
{
	std::cout << "[DiamondTrap] copy constructor called" << std::endl;
	*this = obj;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "[DiamondTrap] Destructor called" << std::endl;
	this->name = "Undefined";
	ClapTrap::name = "Undefined";
}

// Overload Operators;
const DiamondTrap& DiamondTrap::operator=	( const DiamondTrap &obj )
{
	this->name = obj.name;
	this->Hit_points = obj.Hit_points;
	this->Energy_points = obj.Energy_points;
	this->Attack_damage = obj.Attack_damage;
	return (*this);
}

// Member functions;
void DiamondTrap::whoAmI	( void )
{
	std::cout << "ClapTrap name: " << ClapTrap::name << ", " << "DiamondTrap name: " << this->name << std::endl;
}