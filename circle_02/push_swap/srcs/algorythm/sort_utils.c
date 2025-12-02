/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:14:05 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:51:09 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** If list is sorted return 1; If list unsorted return 0;
*/

int	is_sorted(t_listc *stack)
{
	t_listc	*current;

	current = stack->next;
	while (current->next != stack)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

/* 
**	After the stack being sorted it sometimes not in the right order so 
**	we search for the min to put it to the end
**	So the stack is in the right order after
*/

void	last_rotation(t_listc *stack_a)
{
	int	num_rot;

	num_rot = get_cheapest_rota(stack_a, get_min(stack_a));
	if (num_rot >= 0)
		rotate_n(stack_a, 'a', num_rot);
	else
		reverse_rotate_n(stack_a, 'a', -num_rot);
}
