/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:53:42 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 17:49:17 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_node **stack_a, t_node **stack_b, int *move_count)
{
	int	pivot;
	int	best_element;
	int size;

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

int find_pivot(t_node *stack)
{
    int     first;
    int     middle;
    int     last;
    int     size;
    t_node  *current;
    int     i;

    size = get_stack_size(stack);
    first = stack->value;
    current = stack;
    i = 0;
    while (i < size / 2)
    {
        current = current->next;
        i++;
    }
    middle = current->value;
    while (current->next)
        current = current->next;
    last = current->value;
    if ((first <= middle && middle <= last) || (last <= middle && middle <= first))
        return (middle);
    if ((middle <= first && first <= last) || (last <= first && first <= middle))
        return (first);
    return (last);
}

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
