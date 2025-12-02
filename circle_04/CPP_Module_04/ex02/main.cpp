/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:44:43 by nsaillez          #+#    #+#             */
/*   Updated: 2025/10/20 10:22:50 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	//const Animal* k = new Animal();

	i->makeSound();
	j->makeSound();
	//k->makeSound();
	return 0;
}