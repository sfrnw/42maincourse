/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:47:08 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/04 14:35:11 by asafrono         ###   ########.fr       */
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
void	sa(t_node **stack_a);
void	pa(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rra(t_node **stack_a);
// b
void	sb(t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	rb(t_node **stack_b);
void	rrb(t_node **stack_b);
// ab
void	ss(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
//bubble sorting
void	bubble_sorting(t_node **stack_a, t_node **stack_b, int size);
int		get_stack_size(t_node *stack);
// quick sorting
void quick_sort_a(t_node **stack_a, t_node **stack_b, int size);
void quick_sort_b(t_node **stack_a, t_node **stack_b, int size);
int find_pivot(t_node *stack, int size);
int partition_a(t_node **stack_a, t_node **stack_b, int size, int pivot);
int partition_b(t_node **stack_a, t_node **stack_b, int size, int pivot);
int is_sorted_descending(t_node *stack, int size);
void merge_from_b(t_node **stack_a, t_node **stack_b, int size);

// int get_nth_value(t_node *stack, int n);
// void quick_sorting(t_node **stack_a, t_node **stack_b, int l, int r);
// int partition(t_node **stack_a, t_node **stack_b, int l, int r);
// void swap_elements(t_node **stack_a, t_node **stack_b, int index1, int index2);



// sort small
void sort_small_3_a(t_node **stack);
void sort_small_3_b(t_node **stack_b);
void sort_small(t_node **stack, int size);
void sort_small_b(t_node **stack_a, t_node **stack_b, int size);
void sort_small_a(t_node **stack_a, int size);
void sort_stack(t_node **stack_a, t_node **stack_b);
//main
void	print_stack(t_node *stack);

//radix sorting
int get_max(t_node *stack);
void radix_sorting(t_node **stack_a, t_node **stack_b, int size, int *move_count);
void optimized_radix_sort(t_node **stack_a, t_node **stack_b, int *move_count);


#endif