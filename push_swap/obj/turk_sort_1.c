/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:53:42 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/07 16:15:44 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_node **stack_a, t_node **stack_b, int *move_count)
{
	int	pivot;
	int	best_element;
	int	size;

	size = get_stack_size(*stack_a);
	while (size > 3)
	{
		pivot = find_pivot(*stack_a);
		partition_stack(stack_a, stack_b, pivot, move_count);
		size = get_stack_size(*stack_a);
	}
	sort_small(stack_a, size, move_count);
	while (*stack_b)
	{
		best_element = find_best_element(*stack_a, *stack_b);
		move_to_top(stack_b, best_element, move_count);
		insert_element(stack_a, stack_b, move_count);
	}
	rotate_to_min(stack_a, move_count);
}

// This function finds a pivot element for partitioning the stack. 
int	find_pivot(t_node *stack)
{
	int	values[5];
	int	i;
	int	j;
	int	temp;

	if (get_stack_size(stack) < 5)
		return (stack->value);
	select_and_sort_elements(stack, values);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4 - i)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (values[2]);
}

//  This function selects 5 elements from the stack for pivot selection. 
void	select_and_sort_elements(t_node *stack, int *values)
{
	t_node	*elements[5];
	int		i;

	i = -1;
	while (++i < 5)
		elements[i] = stack;
	i = -1;
	while (++i < get_stack_size(stack) / 4)
		elements[1] = elements[1]->next;
	i = -1;
	while (++i < get_stack_size(stack) / 2)
		elements[2] = elements[2]->next;
	i = -1;
	while (++i < 3 * get_stack_size(stack) / 4)
		elements[3] = elements[3]->next;
	while (elements[4]->next)
		elements[4] = elements[4]->next;
	i = -1;
	while (++i < 5)
		values[i] = elements[i]->value;
}

//  This function partitions stack A based on the pivot. 
void	partition_stack(t_node **stack_a, t_node **stack_b, int pivot,
							int *move_count)
{
	int	size;
	int	i;

	size = get_stack_size(*stack_a);
	i = -1;
	while (++i < size)
	{
		if ((*stack_a)->value <= pivot)
			*move_count += pb(stack_a, stack_b);
		else
			*move_count += ra(stack_a);
	}
}
