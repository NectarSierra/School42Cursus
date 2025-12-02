/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:19:58 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 11:18:44 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_listc
{
	int				value;
	int				cost_stack_a;
	int				cost_stack_b;
	int				total_cost;
	struct s_listc	*previous;
	struct s_listc	*next;
}	t_listc;

/*Main.c*/
int			count_args(t_listc *stack);
void		initialize_sort(t_listc *s_a, t_listc *s_b);

/*Algorythm/*/
/*Median_sort.c*/
int			is_array_sorted(int *array, int nb_arg);
int			*set_array(t_listc *s_a, int *bubble_array);
int			*bubblesort_array(t_listc *s_a, int nb_arg);
void		median_sort(t_listc *s_a, t_listc *s_b, int nb_arg);
/*Small_sort.c*/
void		sort_small(t_listc *s_a, t_listc *s_b, int nb_arg);
void		sort_3(t_listc *stack);
/*Sort_utils.c*/
int			is_sorted(t_listc *stack);
void		last_rotation(t_listc *s_a);
/*Sort.c*/
t_listc		*get_min(t_listc *stack);
t_listc		*get_max(t_listc *stack);
int			get_cheapest_rota(t_listc *stack, t_listc *element_searched);
int			get_above_rota(t_listc *stack, t_listc *element);
/*Turk_sort.c*/
t_listc		*get_cheapest_cost(t_listc *s_b);
int			sum_cost(int cost_stack_a, int cost_stack_b);
void		calculate_cost(t_listc *s_a, t_listc *s_b);
void		turk_sort(t_listc *s_a, t_listc *s_b, int nb_arg);
/*Apply_rotation.c*/
int			apply_reverse_rotation_both(int rrr, t_listc *element);
int			apply_rotation_both(int rr, t_listc *element);
void		apply_rotation(t_listc *s_a, t_listc *s_b, t_listc *element);

/*Arguments/*/
/*Arg_manager.c*/
int			args_to_int_error(char **pre_arg, int j);
int			args_to_int(int argc, char **argv, t_listc **s_a, t_listc **s_b);
int			check_for_dup(t_listc *cstack_a, t_listc *cstack_b);
/*Arg_overflow.c*/
int			overflow_check(int res, int digit, int isneg);
int			char_to_int_overflow(char *str);

/*List/*/
/*List_manager.c*/
t_listc		*create_cirlist(void);
void		add_new_node_after(t_listc *node, int val);
void		add_new_node_before(t_listc *node, int val);
void		push_to_end(t_listc *root, int val);
void		push_to_start(t_listc *root, int val);
/*List_free.c*/
void		list_delete(t_listc *lst);
void		list_cleanup(t_listc *lst);
void		list_clean_both(t_listc *stack_a, t_listc *stack_b);

/*Operations/*/
/*Push.c*/
int			push(t_listc *stack_get, t_listc *stack_rem, char c);
void		push_n(t_listc *stack_1, t_listc *stack_2, char c, int number);
/*Rotate_n.c*/
void		rotate_n(t_listc *stack, char c, int number);
void		reverse_rotate_n(t_listc *stack, char c, int number);
void		reverse_rotate_both_n(t_listc *s_a, t_listc *s_b, int number);
void		rotate_both_n(t_listc *s_a, t_listc *s_b, int number);
/*Rotate.c*/
int			rotate(t_listc *stack, char c);
int			rotate_both(t_listc *s_a, t_listc *s_b, int needprint);
int			reverse_rotate(t_listc *stack, char c);
int			reverse_rotate_both(t_listc *s_a, t_listc *s_b, int needprint);
/*Swap.c*/
int			swap(t_listc *stack, char c);
void		swap_both(t_listc *s_a, t_listc *s_b);

#endif