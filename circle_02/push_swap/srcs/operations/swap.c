/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:28:06 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:18:44 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_listc *stack, char c)
{
	t_listc		*first_element;
	t_listc		*second_element;

	first_element = stack->previous;
	if (first_element == stack)
		return (-1);
	second_element = first_element->previous;
	if (second_element == stack)
		return (-1);
	stack->previous = second_element;
	second_element->next = stack;
	second_element->previous->next = first_element;
	first_element->next = second_element;
	first_element->previous = second_element->previous;
	second_element->previous = first_element;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
	return (0);
}

void	swap_both(t_listc *stack_a, t_listc *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	write(1, "ss\n", 3);
}
