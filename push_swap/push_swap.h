/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:47:08 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/27 17:27:01 by asafrono         ###   ########.fr       */
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
//sorting
void	bubble_sorting(t_node **stack_a, t_node **stack_b);
int		get_stack_size(t_node *stack);

#endif