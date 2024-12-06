/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:45:31 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 12:42:48 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_median(t_node *stack)
{
	int *arr;
	int size;
	int median;
	int i, j, min_idx, temp;

	size = get_stack_size(stack);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);

	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}

	// Selection sort (more efficient than bubble sort)
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}
	}

	median = arr[size / 2];
	free(arr);
	return (median);
}


static void partition_stack(t_node **stack_a, t_node **stack_b, int median, int *move_count)
{
	int size = get_stack_size(*stack_a);
	for (int i = 0; i < size; i++)
	{
		if ((*stack_a)->value <= median)
		{
			pb(stack_a, stack_b);
		}
		else
		{
			ra(stack_a);
		}
		(*move_count)++;
	}
}



static int find_min_position(t_node *stack)
{
	int min_value;
	int min_position;
	int current_position;
	t_node *current;

	if (!stack)
		return 0;

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

static int find_insertion_point(t_node *stack_a, int value)
{
	int position = 0;
	t_node *current = stack_a;
	t_node *first = stack_a;

	if (!stack_a)
		return 0;
	do
	{
		t_node *next;
		if (current->next)
			next = current->next;
		else
			next = first;

		if (value > current->value && value <= next->value)
			return (position + 1) % get_stack_size(stack_a);

		current = next;
		position++;
	} while (current != first);
	// If we've gone through the entire stack, insert at the minimum element
	return find_min_position(stack_a);
}

static int calculate_cost(t_node *stack_a, t_node *stack_b, int element, int position_b)
{
	int size_a = get_stack_size(stack_a);
	int size_b = get_stack_size(stack_b);
	int insertion_point = find_insertion_point(stack_a, element);
	int cost_a;
	int cost_b;

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

static int find_best_element(t_node *stack_a, t_node *stack_b)
{
	int best_element = stack_b->value;
	int min_cost = INT_MAX;
	int position = 0;
	t_node *current = stack_b;

	while (current)
	{
		int cost = calculate_cost(stack_a, stack_b, current->value, position);
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

static void move_to_top(t_node **stack, int value, int *move_count)
{
	int position = 0;
	int size = get_stack_size(*stack);
	t_node *current = *stack;

	while (current && current->value != value)
	{
		position++;
		current = current->next;
	}

	if (position <= size / 2)
	{
		while ((*stack)->value != value)
		{
			rb(stack);
			(*move_count)++;
		}
	}
	else
	{
		while ((*stack)->value != value)
		{
			rrb(stack);
			(*move_count)++;
		}
	}
}

static void insert_element(t_node **stack_a, t_node **stack_b, int *move_count)
{
	int insertion_point = find_insertion_point(*stack_a, (*stack_b)->value);
	int size = get_stack_size(*stack_a);
	int rotations;

	if (insertion_point <= size / 2)
	{
		rotations = insertion_point;
		while (rotations > 0)
		{
			ra(stack_a);
			(*move_count)++;
			rotations--;
		}
	}
	else
	{
		rotations = size - insertion_point;
		while (rotations > 0)
		{
			rra(stack_a);
			(*move_count)++;
			rotations--;
		}
	}

	pa(stack_a, stack_b);
	(*move_count)++;
}

static void rotate_to_min(t_node **stack, int *move_count)
{
	t_node *min_node = *stack;
	t_node *current = *stack;
	int min_pos = 0;
	int current_pos = 0;
	int size = get_stack_size(*stack);

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

	if (min_pos <= size / 2)
	{
		while (min_pos--)
		{
			ra(stack);
			(*move_count)++;
		}
	}
	else
	{
		while (min_pos++ < size)
		{
			rra(stack);
			(*move_count)++;
		}
	}
}

void turk_sort(t_node **stack_a, t_node **stack_b, int size, int *move_count)
{
	while (size > 3)
	{
		int median = find_median(*stack_a);
		partition_stack(stack_a, stack_b, median, move_count);
		size = get_stack_size(*stack_a);
	}

	// Sort the remaining elements in stack_a (3 or fewer)
	sort_small(stack_a, size, move_count);

	// Find optimal insertion points and insert back to stack_a
	while (*stack_b)
	{
		int best_element = find_best_element(*stack_a, *stack_b);
		move_to_top(stack_b, best_element, move_count);
		insert_element(stack_a, stack_b, move_count);
	}

	// Final rotation to put minimum on top
	rotate_to_min(stack_a, move_count);
}
