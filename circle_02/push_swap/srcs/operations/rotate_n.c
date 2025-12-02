/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:20:25 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 10:24:47 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_n(t_listc *stack, char c, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		rotate(stack, c);
		i++;
	}
}

void	reverse_rotate_n(t_listc *stack, char c, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		reverse_rotate(stack, c);
		i++;
	}
}

void	reverse_rotate_both_n(t_listc *stack_a, t_listc *stack_b, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		reverse_rotate_both(stack_a, stack_b, 1);
		i++;
	}
}

void	rotate_both_n(t_listc *stack_a, t_listc *stack_b, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		rotate_both(stack_a, stack_b, 1);
		i++;
	}
}
