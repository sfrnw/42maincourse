/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:47:08 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 14:33:05 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

//pushswap file
void	handle_error(t_node **stack);
t_node	*parse_arguments(int argc, char **argv);
void	free_stack(t_node **stack);
int		is_sorted(t_node *stack);
//stack operations
t_node	*create_node(int value);
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
//radix optimized sorting 
void	radix_sort2(t_node **stack_a, t_node **stack_b,
			int *move_count);
// turk sorting
void	turk_sort(t_node **stack_a, t_node **stack_b,
			int size, int *move_count);

#endif