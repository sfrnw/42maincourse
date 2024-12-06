/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:04 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 13:53:55 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *stack)
{
	int	max;
	int	bits;

	max = 0;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	bits = 0;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

static void	push_based_on_bit(t_node **stack_a, t_node **stack_b,
			int bit, int *move_count)
{
	int	size;
	int	i;

	size = get_stack_size(*stack_a);
	i = 0;
	while (i < size)
	{
		if (((*stack_a)->value >> bit) & 1)
			*move_count += ra(stack_a);
		else
			*move_count += pb(stack_a, stack_b);
		i++;
	}
}

static void	empty_stack_b(t_node **stack_a, t_node **stack_b, int *move_count)
{
	while (*stack_b)
		*move_count += pa(stack_a, stack_b);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int *move_count)
{
	int	max_bits;
	int	bit;

	max_bits = get_max_bits(*stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		push_based_on_bit(stack_a, stack_b, bit, move_count);
		empty_stack_b(stack_a, stack_b, move_count);
		bit++;
	}
}
