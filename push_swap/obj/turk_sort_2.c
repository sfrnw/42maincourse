/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:45:31 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/10 16:44:36 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	This function finds the element in stack B 
//	that would be the most efficient to move to stack A.
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
//This function iterates through stack B, calculating the cost
// of moving each element to stack A. It keeps track of the 
// element with the lowest cost and returns it as the best element to move.

//  This function calculates the cost of moving
//	an element from stack B to stack A. 
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

//	This function finds the correct position
//	to insert an element into stack A. 
int	find_insertion_point(t_node *stack_a, int element)
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
		if (element > current->value && element <= next->value)
			return ((position + 1) % get_stack_size(stack_a));
		current = next;
		position++;
		if (current == first)
			break ;
	}
	return (find_min_position(stack_a));
}

// This function finds the position of the minimum value in a stack. 
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
// This function iterates through the stack, keeping
// track of the smallest value encountered and its position.
// It returns the position of the minimum value in the stack.

// find_insertion_point
// This function determines where in stack A a given value should be inserted:
// It iterates through stack A, treating it as a circular list.
// It looks for a position where the value is greater than the current 
// node's value and less than or equal to the next node's value.
//
// If such a position is found, it returns the index of the next node 
// (modulo the stack size to handle wrap-around).
// position + 1: We add 1 to the current position because we want to insert
// the element after the current node.
// % get_stack_size(stack_a): This is the modulo operation. It's used to handle
// the case where the insertion point is at the end of the stack.
// If position + 1 is less than the stack size, the modulo operation 
// doesn't change the value.
// If position + 1 equals the stack size, the modulo operation will
//  return 0, indicating that the element should be inserted at the
// beginning of the stack.
//
// If no suitable position is found (which happens when the value is
// smaller than all elements in stack A), it calls find_min_position to
// find where the smallest element in stack A is located.
