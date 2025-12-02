/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:17:41 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/24 10:30:24 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

// Constructor( void | std::string ), copy constructor, destructor;
ScavTrap::ScavTrap( void )
{
	std::cout << "[ScavTrap] Default constructor called" << std::endl;
	this->name = "Undefined";
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap( std::string name )
{
	std::cout << "[ScavTrap] Default constructor called" << std::endl;
	this->name = name;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &obj )
{
	*this = obj;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "[ScavTrap] Destructor called" << std::endl;
}

// Overload Operators;
const ScavTrap& ScavTrap::operator=( const ScavTrap &obj )
{
	this->name = obj.name;
	this->Hit_points = obj.Hit_points;
	this->Energy_points = obj.Energy_points;
	this->Attack_damage = obj.Attack_damage;
	return (*this);
}

// Member Functions;
void ScavTrap::attack( const std::string& target )
{
	if (Hit_points <= 0)
	{
		std::cout << "[ScavTrap] " << this->name << " is dead!" << std::endl;
		return;
	}
	if (Energy_points <= 0)
	{
		std::cout << "[ScavTrap] " << this->name << " has not enough energy!" << std::endl;
		return;
	}
	--this->Energy_points;
	std::cout << "[ScavTrap] " << this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "[ScavTrap] " << this->name << " is now in Gatekeeper mode. " << std::endl;
}