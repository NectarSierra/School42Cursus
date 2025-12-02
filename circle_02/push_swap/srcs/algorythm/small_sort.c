/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:35:09 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:53:01 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Used to sort small amount of number from 4 to 6.
*/

void	sort_small(t_listc *stack_a, t_listc *stack_b, int number_of_arg)
{
	int	number_to_push;

	number_to_push = (number_of_arg - 3);
	push_n(stack_b, stack_a, 'b', number_to_push);
	sort_3(stack_a);
	turk_sort(stack_a, stack_b, number_to_push);
}

/*
** Used to only sort 3 number.
*/

void	sort_3(t_listc *stack)
{
	while (stack->next->value < stack->previous->value)
		rotate(stack, 'a');
	if (stack->previous->value > stack->previous->previous->value)
		swap(stack, 'a');
	if (!is_sorted(stack))
	{
		reverse_rotate(stack, 'a');
		swap(stack, 'a');
	}
}
