/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:38:29 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 11:10:24 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	apply_reverse_rotation_both(int rrr, t_listc *element)
{
	if ((-element->cost_stack_a) > (-element->cost_stack_b))
	{
		rrr = -element->cost_stack_b;
		element->cost_stack_a = (element->cost_stack_a + rrr);
		element->cost_stack_b = 0;
	}
	else
	{
		rrr = -element->cost_stack_a;
		element->cost_stack_a = 0;
		element->cost_stack_b = (element->cost_stack_b + rrr);
	}
	return (rrr);
}

int	apply_rotation_both(int rr, t_listc *element)
{
	if ((element->cost_stack_a) > (element->cost_stack_b))
	{
		rr = element->cost_stack_b;
		element->cost_stack_a = (element->cost_stack_a - rr);
		element->cost_stack_b = 0;
	}
	else
	{
		rr = element->cost_stack_a;
		element->cost_stack_a = 0;
		element->cost_stack_b = (element->cost_stack_b - rr);
	}
	return (rr);
}

void	apply_rotation(t_listc *stack_a, t_listc *stack_b, t_listc *element)
{
	int	rotation;

	rotation = 0;
	if (element->cost_stack_a < 0 && element->cost_stack_b < 0)
	{
		rotation = apply_reverse_rotation_both(rotation, element);
		reverse_rotate_both_n(stack_a, stack_b, rotation);
	}
	if (element->cost_stack_a >= 0 && element->cost_stack_b >= 0)
	{
		rotation = apply_rotation_both(rotation, element);
		rotate_both_n(stack_a, stack_b, rotation);
	}
	if (element->cost_stack_a < 0)
		reverse_rotate_n(stack_a, 'a', (-element->cost_stack_a));
	else
		rotate_n(stack_a, 'a', element->cost_stack_a);
	if (element->cost_stack_b < 0)
		reverse_rotate_n(stack_b, 'b', (-element->cost_stack_b));
	else
		rotate_n(stack_b, 'b', element->cost_stack_b);
}
