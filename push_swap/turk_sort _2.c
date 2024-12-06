/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort _2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:45:31 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 14:54:15 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_element(t_node *stack_a, t_node *stack_b)
{
	int		best_element;
	int		min_cost;
	int		position;
	t_node	*current;
	int		cost;

	best_element = stack_b->value;
	min_cost = INT_MAX;
	position = 0;
	current = stack_b;
	while (current)
	{
		cost = calculate_cost(stack_a, stack_b, current->value, position);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_element = current->value;
		}
		current = current->next;
		position++;
	}
	return (best_element);
}

void	move_to_top(t_node **stack, int value, int *move_count)
{
	int		position;
	int		size;
	t_node	*current;

	position = 0;
	size = get_stack_size(*stack);
	current = *stack;
	while (current && current->value != value)
	{
		position++;
		current = current->next;
	}
	if (position <= size / 2)
		while ((*stack)->value != value)
			*move_count += rb(stack);
	else
		while ((*stack)->value != value)
			*move_count += rrb(stack);
}

void	insert_element(t_node **stack_a, t_node **stack_b, int *move_count)
{
	int	insertion_point;
	int	size;
	int	rotations;

	insertion_point = find_insertion_point(*stack_a, (*stack_b)->value);
	size = get_stack_size(*stack_a);
	if (insertion_point <= size / 2)
	{
		rotations = insertion_point;
		while (rotations > 0)
		{
			*move_count += ra(stack_a);
			rotations--;
		}
	}
	else
	{
		rotations = size - insertion_point;
		while (rotations > 0)
		{
			*move_count += rra(stack_a);
			rotations--;
		}
	}
	*move_count += pa(stack_a, stack_b);
}

void	rotate_stack_to_position(t_node **stack, int pos, int size,
									int *move_count)
{
	if (pos <= size / 2)
		while (pos--)
			*move_count += ra(stack);
	else
		while (pos++ < size)
			*move_count += rra(stack);
}

void	rotate_to_min(t_node **stack, int *move_count)
{
	t_node	*min_node;
	t_node	*current;
	int		min_pos;
	int		current_pos;
	int		size;

	min_node = *stack;
	current = *stack;
	min_pos = 0;
	current_pos = 0;
	size = get_stack_size(*stack);
	while (current)
	{
		if (current->value < min_node->value)
		{
			min_node = current;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	rotate_stack_to_position(stack, min_pos, size, move_count);
}