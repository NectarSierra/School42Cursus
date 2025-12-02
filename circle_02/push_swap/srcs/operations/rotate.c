/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:28:04 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:21:30 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_listc *stack, char c)
{
	if (stack->previous == stack)
		return (-1);
	if (stack->previous->previous == stack)
		return (-1);
	stack->previous = stack->previous->previous;
	stack->previous->next->previous = stack;
	stack->next->previous = stack->previous->next;
	stack->previous->next->next = stack->next;
	stack->next = stack->previous->next;
	stack->previous->next = stack;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
	return (0);
}

int	rotate_both(t_listc *stack_a, t_listc *stack_b, int needprint)
{
	int	temp;

	temp = rotate(stack_a, 0);
	if (rotate(stack_b, 0) == -1 || temp)
		return (-1);
	if (needprint == 1)
		write(1, "rr\n", 3);
	return (0);
}

int	reverse_rotate(t_listc *stack, char c)
{
	if (stack->previous == stack)
		return (-1);
	if (stack->previous->previous == stack)
		return (-1);
	stack->next = stack->next->next;
	stack->next->previous->next = stack;
	stack->previous->next = stack->next->previous;
	stack->next->previous->previous = stack->previous;
	stack->previous = stack->next->previous;
	stack->next->previous = stack;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
	return (0);
}

int	reverse_rotate_both(t_listc *stack_a, t_listc *stack_b, int needprint)
{
	int	temp;

	temp = reverse_rotate(stack_a, 0);
	if (reverse_rotate(stack_b, 0) == -1 || temp)
		return (-1);
	if (needprint == 1)
		write(1, "rrr\n", 4);
	return (0);
}
