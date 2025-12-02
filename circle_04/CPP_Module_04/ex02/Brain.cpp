/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:33:58 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 16:06:56 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "Brain.h"

Brain::Brain( void )
{
	std::cout << "[Brain] Default constructor called!" << std::endl;
	int i = 0;

	while (i < 100)
	{
		this->ideas[i] = "";
		i++;
	}
}

Brain::Brain( const Brain &obj)
{
	std::cout << "[Brain] Copy constructor called!" << std::endl;
	*this = obj;
}

Brain::~Brain( void )
{
	std::cout << "[Brain] Destructor called!" << std::endl;
}

const Brain& Brain::operator= (const Brain &obj)
{
	std::cout << "[Brain] Overload operator= called!" << std::endl;
	int i = 0;

	while (i < 100)
	{
		this->ideas[i] = obj.ideas[i];
		i++;
	}
	return (*this);
}

void Brain::print_ideas( int j )
{
	int i = 0;

	if (j > 100)
		j = 100;
	while (i < j)
	{
		std::cout << "[" << i << "] " << this->ideas[i] << std::endl;
		i++;
	}
}

void Brain::change_ideas( std::string in )
{
	int i = 0;

	while (i < 100)
	{
		this->ideas[i] = in;
		i++;
	}
}