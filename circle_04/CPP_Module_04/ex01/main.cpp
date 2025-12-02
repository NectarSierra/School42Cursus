/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:44:43 by nsaillez          #+#    #+#             */
/*   Updated: 2025/10/21 16:40:10 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;

	const Animal* arr[2];
	const Animal* a = new Dog();
	const Animal* b = new Cat();
	arr[0] = a;
	arr[1] = b;
	arr[0]->makeSound();
	arr[1]->makeSound();
	delete arr[0];
	delete arr[1];

	std::cout << std::endl;

	const Cat* ca = new Cat();
	ca->print_brain(5);
	ca->apply_change("Hello!");
	ca->print_brain(5);
	const Cat cb = *ca;
	cb.print_brain(5);
	delete ca;
	cb.print_brain(5);
	
	return 0;
}