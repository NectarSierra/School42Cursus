/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:23:41 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 11:42:30 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../srcs/push_swap.h"

int	compare_2_str(char *str_1, char *str_2)
{
	int	i;

	i = 0;
	while (str_1[i] != '\0' && str_1[i] != '\0' && (str_1[i] == str_2[i]))
		i++;
	if (str_1[i] != str_2[i])
		return (-1);
	return (1);
}

int	check_operation(char *operation, t_listc *stack_a, t_listc *stack_b)
{
	if (compare_2_str("pa\n", operation) == 1)
		return (push(stack_a, stack_b, 0));
	if (compare_2_str("pb\n", operation) == 1)
		return (push(stack_b, stack_a, 0));
	if (compare_2_str("ra\n", operation) == 1)
		return (rotate(stack_a, 0));
	if (compare_2_str("rb\n", operation) == 1)
		return (rotate(stack_b, 0));
	if (compare_2_str("rra\n", operation) == 1)
		return (reverse_rotate(stack_a, 0));
	if (compare_2_str("rrb\n", operation) == 1)
		return (reverse_rotate(stack_b, 0));
	if (compare_2_str("rr\n", operation) == 1)
		return (rotate_both(stack_a, stack_b, 0));
	if (compare_2_str("rrr\n", operation) == 1)
		return (reverse_rotate_both(stack_a, stack_b, 0));
	if (compare_2_str("sa\n", operation) == 1)
		return (swap(stack_a, 0));
	if (compare_2_str("sb\n", operation) == 1)
		return (swap(stack_b, 0));
	return (-1);
}

/*
void print_both(t_listc *stack_a, t_listc *stack_b)
{
	t_listc *current_a;
	t_listc *current_b;

	printf("A > ");
	current_a = stack_a->next;
	while (current_a != stack_a)
	{
		printf(" %d",current_a->value);
		current_a = current_a->next;
	}
	printf("\n");
	printf("B > ");
	current_b = stack_b->next;
	while (current_b != stack_b)
	{
		printf(" %d",current_b->value);
		current_b = current_b->next;
	}
	printf("\n");
}
*/

int	get_operations(t_listc *stack_a, t_listc *stack_b)
{
	char	*res;
	char	*red;

	red = "\033[31m";
	res = get_next_line(0);
	while (res != NULL)
	{
		if (res != NULL)
		{
			if (check_operation(res, stack_a, stack_b) == -1)
			{
				write(2, red, 5);
				write(2, "Error - A command did nothing!\n", 32);
				write(2, "\033[0m", 5);
				free(res);
				list_clean_both(stack_a, stack_b);
				return (-1);
			}
			free(res);
		}
		res = get_next_line(0);
	}
	free(res);
	return (0);
}

int	is_sorted_bonus(t_listc *stack, t_listc *stack_b)
{
	t_listc	*current;
	char	*red;

	red = "\033[31m";
	current = stack->next;
	while (current->next != stack)
	{
		if (current->value < current->next->value)
		{
			write(2, red, 5);
			write(1, "KO\n", 3);
			write(2, "\033[0m", 5);
			list_clean_both(stack, stack_b);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_listc		*stack_a;
	t_listc		*stack_b;
	const char	*green;

	green = "\e[0;32m";
	stack_a = create_cirlist();
	stack_b = create_cirlist();
	if (argc > 1)
	{
		if (args_to_int(argc, argv, &stack_a, &stack_b) == -1)
			return (-1);
		if (check_for_dup(stack_a, stack_b) == -1)
			return (-1);
		if (get_operations(stack_a, stack_b) == -1)
			return (-1);
		if (!is_sorted_bonus(stack_a, stack_b))
			return (-1);
		write(1, green, 7);
		write(1, "OK\n", 3);
		write(2, "\033[0m", 5);
	}
	list_clean_both(stack_a, stack_b);
	return (0);
}
