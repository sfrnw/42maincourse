/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:21:15 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/28 17:52:04 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*top_b;

	if (*stack_b == NULL)
		return ;
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	push(stack_a, top_b);
	write(1, "pa\n", 3);
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "pa\n", 3);
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}
