/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:28:00 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:26:45 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_listc *stack_get, t_listc *stack_rem, char c)
{
	t_listc	*last_element;

	last_element = stack_rem->previous;
	if (last_element == stack_rem)
		return (-1);
	stack_rem->previous = last_element->previous;
	last_element->previous->next = stack_rem;
	stack_get->previous->next = last_element;
	last_element->previous = stack_get->previous;
	stack_get->previous = last_element;
	last_element->next = stack_get;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
	return (0);
}

void	push_n(t_listc *first_stack, t_listc *second_stack, char c, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		push(first_stack, second_stack, c);
		i++;
	}
}
