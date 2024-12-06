/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:45:31 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 15:29:27 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_node *stack)
{
	int	*arr;
	int	size;
	int	median;
	int	i;

	size = get_stack_size(stack);
	arr = (int *)ft_calloc(size, sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	ft_memcpy(arr, arr, size * sizeof(int));
	ft_qsort(arr, 0, size - 1);
	median = arr[size / 2];
	free(arr);
	return (median);
}

void	partition_stack(t_node **stack_a, t_node **stack_b, int median,
							int *move_count)
{
	int	size;
	int	i;

	size = get_stack_size(*stack_a);
	i = -1;
	while (++i < size)
	{
		if ((*stack_a)->value <= median)
			*move_count += pb(stack_a, stack_b);
		else
			*move_count += ra(stack_a);
	}
}

int	find_min_position(t_node *stack)
{
	int		min_value;
	int		min_position;
	int		current_position;
	t_node	*current;

	if (!stack)
		return (0);
	min_value = stack->value;
	min_position = 0;
	current_position = 0;
	current = stack;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_position = current_position;
		}
		current = current->next;
		current_position++;
	}
	return (min_position);
}

int	find_insertion_point(t_node *stack_a, int value)
{
	int		position;
	t_node	*current;
	t_node	*first;
	t_node	*next;

	position = 0;
	current = stack_a;
	first = stack_a;
	if (!stack_a)
		return (0);
	while (1)
	{
		if (current->next)
			next = current->next;
		else
			next = first;
		if (value > current->value && value <= next->value)
			return ((position + 1) % get_stack_size(stack_a));
		current = next;
		position++;
		if (current == first)
			break ;
	}
	return (find_min_position(stack_a));
}

int	calculate_cost(t_node *stack_a, t_node *stack_b, int element,
								int position_b)
{
	int								size_a;
	int								size_b;
	int								insertion_point;
	int								cost_a;
	int								cost_b;

	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	insertion_point = find_insertion_point(stack_a, element);
	if (insertion_point < size_a / 2)
		cost_a = insertion_point;
	else
		cost_a = size_a - insertion_point;
	if (position_b < size_b / 2)
		cost_b = position_b;
	else
		cost_b = size_b - position_b;
	return (cost_a + cost_b);
}
