/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:49:04 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/28 13:16:51 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	pivot;
	int	pushed;
	if (size <= 1)
        return ;
	if (size <= 3)
	{
		sort_small(stack_a, size);
		return ;
	}
	pivot = get_pivot(*stack_a, size);
	pushed = partition(stack_a, stack_b, pivot, size);
	quick_sort(stack_b, stack_a, pushed);
	quick_sort(stack_a, stack_b, size - pushed);
	while (pushed--)
		pa(stack_a, stack_b);
}

int	partition(t_node **stack_a, t_node **stack_b, int pivot, int size)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	while (size--)
	{
		if ((*stack_a)->value < pivot)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
		{
			ra(stack_a);
			rotated++;
		}
	}
	while (rotated--)
		rra(stack_a);
	return (pushed);
}

int	get_pivot(t_node *stack, int size)
{
	t_node	*current;
	int		i;
	if (!stack)
        return 0;
	current = stack;
	i = size / 2;
	while (i-- > 0 && current->next)
		current = current->next;
	return (current ? current->value : stack->value);
}

void	sort_small(t_node **stack, int size)
{
	if (size == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else if (size == 3)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		if ((*stack)->next->value > (*stack)->next->next->value)
		{
			rra(stack);
			if ((*stack)->value > (*stack)->next->value)
				sa(stack);
		}
	}
}
