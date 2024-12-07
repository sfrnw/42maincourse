/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:47:08 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/07 19:20:48 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

//push_swap
void	ft_free_split(char **split);
t_node	*process_argument(char *arg, t_node **stack_a);
t_node	*parse_arguments(int argc, char **argv);
int		main(int argc, char **argv);

//stack errors
int		is_sorted(t_node *stack);
int		has_duplicate(t_node *stack);
void	handle_error(t_node **stack);

//stack operations
t_node	*create_node(int value);
void	free_stack(t_node **stack);
int		get_stack_size(t_node *stack);
void	print_stack(t_node *stack);
void	push(t_node **stack, t_node *new_node);
t_node	*pop(t_node **stack);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);

// a
int		sa(t_node **stack_a);
int		pa(t_node **stack_a, t_node **stack_b);
int		ra(t_node **stack_a);
int		rra(t_node **stack_a);

// b
int		sb(t_node **stack_b);
int		pb(t_node **stack_a, t_node **stack_b);
int		rb(t_node **stack_b);
int		rrb(t_node **stack_b);

// ab
int		ss(t_node **stack_a, t_node **stack_b);
int		rr(t_node **stack_a, t_node **stack_b);
int		rrr(t_node **stack_a, t_node **stack_b);

//bubble sorting
void	bubble_sorting(t_node **stack_a, t_node **stack_b, int size);

// sort small
void	sort_small(t_node **stack, int size, int *move_count);

//main
void	print_stack(t_node *stack);
int		get_stack_size(t_node *stack);

//radix sorting
void	radix_sort(t_node **stack_a, t_node **stack_b, int *move_count);

// turk sorting
void	select_and_sort_elements(t_node *stack, int *values);
int		find_pivot(t_node *stack);
void	partition_stack(t_node **stack_a, t_node **stack_b, int median,
			int *move_count);
int		find_min_position(t_node *stack);
int		find_insertion_point(t_node *stack_a, int value);
int		calculate_cost(t_node *stack_a, t_node *stack_b, int element,
			int position_b);
int		find_best_element(t_node *stack_a, t_node *stack_b);
void	move_to_top(t_node **stack, int value, int *move_count);
void	insert_element(t_node **stack_a, t_node **stack_b, int *move_count);
void	rotate_stack_to_position(t_node **stack, int pos, int size,
			int *move_count);
void	rotate_to_min(t_node **stack, int *move_count);
void	turk_sort(t_node **stack_a, t_node **stack_b, int *move_count);

#endif