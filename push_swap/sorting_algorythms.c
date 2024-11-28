/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:17:09 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/28 11:39:19 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// bubble
int	get_stack_size(t_node *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

static void	bubble_pass(t_node **stack_a, int size, int *swapped)
{
	int		i;
	t_node	*current;

	i = 0;
	while (i < size - 1)
	{
		current = *stack_a;
		if (current->value > current->next->value)
		{
			sa(stack_a);
			*swapped = 1;
		}
		ra(stack_a);
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		rra(stack_a);
		i++;
	}
}

void	bubble_sorting(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	swapped;

	(void)stack_b;
	size = get_stack_size(*stack_a);
	while (1)
	{
		swapped = 0;
		bubble_pass(stack_a, size, &swapped);
		if (swapped == 0)
			break ;
	}
}
