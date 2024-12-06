/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:21:15 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 14:32:22 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	return (1);
}

int	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*top_b;

	if (*stack_b == NULL)
		return (0);
	top_b = pop(stack_b);
	push(stack_a, top_b);
	write(1, "pa\n", 3);
	return (1);
}

int	ra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return (0);
	rotate(stack_a);
	write(1, "ra\n", 3);
	return (1);
}

int	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	return (1);
}
