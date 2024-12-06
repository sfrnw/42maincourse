/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:17:46 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 11:56:47 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void normalize_stack(t_node **stack)
{
    t_node *current = *stack;
    t_node *temp;
    int index = 0;

    while (current)
    {
        index = 0;
        temp = *stack;
        while (temp)
        {
            if (temp->value < current->value)
                index++;
            temp = temp->next;
        }
        current->index = index;
        current = current->next;
    }
}

static int get_max_index(t_node *stack)
{
    int max = 0;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return max;
}

static void push_based_on_bit(t_node **stack_a, t_node **stack_b, int bit, int *move_count)
{
    int size = get_stack_size(*stack_a);
    for (int i = 0; i < size; i++)
    {
        if (((*stack_a)->index >> bit) & 1)
        {
            ra(stack_a);
            (*move_count)++;
        }
        else
        {
            pb(stack_a, stack_b);
            (*move_count)++;
        }
    }
}

static void	empty_stack_b(t_node **stack_a, t_node **stack_b, int *move_count)
{
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		(*move_count)++;
	}
}

void radix_sort2(t_node **stack_a, t_node **stack_b, int *move_count)
{
    normalize_stack(stack_a);
    int max_index = get_max_index(*stack_a);
    int max_bits = 0;
    while ((max_index >> max_bits) != 0)
        max_bits++;

    for (int bit = 0; bit < max_bits; bit++)
    {
        push_based_on_bit(stack_a, stack_b, bit, move_count);
        empty_stack_b(stack_a, stack_b, move_count);
    }
}
