/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:53:18 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/07 15:32:38 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small_3(t_node **stack, int *move_count)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first >= second && second >= third)
	{
		*move_count += sa(stack);
		*move_count += rra(stack);
	}
	else if (first >= second && second < third && first >= third)
		*move_count += ra(stack);
	else if (first >= second && second < third && first < third)
		*move_count += sa(stack);
	else if (first < second && second >= third && first < third)
	{
		*move_count += sa(stack);
		*move_count += ra(stack);
	}
	else if (first < second && second >= third && first >= third)
		*move_count += rra(stack);
}

void	sort_small(t_node **stack, int size, int *move_count)
{
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			*move_count += sa(stack);
	}
	else if (size == 3)
		sort_small_3(stack, move_count);
}
