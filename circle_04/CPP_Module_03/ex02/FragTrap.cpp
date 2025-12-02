/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:24:45 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/24 09:12:03 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

// Constructor( void | std::string ), copy constructor, destructor;
FragTrap::FragTrap( void )
{
	std::cout << "[FragTrap] Default constructor called" << std::endl;
	this->name = "Undefined";
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap( std::string name )
{
	std::cout << "[FragTrap] Default constructor called" << std::endl;
	this->name = name;
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap( const FragTrap &obj )
{
	*this = obj;
}

FragTrap::~FragTrap( void )
{
	std::cout << "[FragTrap] Destructor called" << std::endl;
}

// Overload Operators;
const FragTrap& FragTrap::operator=	( const FragTrap &obj )
{
	this->name = obj.name;
	this->Hit_points = obj.Hit_points;
	this->Energy_points = obj.Energy_points;
	this->Attack_damage = obj.Attack_damage;
	return (*this);
}

// Member Functions;
void FragTrap::attack( const std::string& target )
{
	if (Hit_points <= 0)
	{
		std::cout << "[FragTrap] " << this->name << " is dead!" << std::endl;
		return;
	}
	if (Energy_points <= 0)
	{
		std::cout << "[FragTrap] " << this->name << " has not enough energy!" << std::endl;
		return;
	}
	--this->Energy_points;
	std::cout << "[FragTrap] " << this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "[FragTrap] Positive hive-fives request!" << std::endl;
}