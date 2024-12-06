/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:53:42 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 14:54:29 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_node **stack_a, t_node **stack_b, int size, int *move_count)
{
	int	median;
	int	best_element;

	while (size > 3)
	{
		median = find_median(*stack_a);
		partition_stack(stack_a, stack_b, median, move_count);
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
