/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:21:15 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/04 17:29:05 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*top_a;

	if (*stack_a == NULL)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	push(stack_b, top_a);
	write(1, "pb\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}
