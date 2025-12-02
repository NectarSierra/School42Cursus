/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:44:43 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/26 09:49:57 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

#include "WrongCat.h"
#include "WrongAnimal.h"

int main( void )
{
	Animal meta;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << meta.getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta.makeSound();
	
	delete dog;
	delete cat;
	
	std::cout << std::endl;
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << wrongcat->getType() << " " << std::endl;
	wrongcat->makeSound();
	delete wrongcat;
	return (0);
}