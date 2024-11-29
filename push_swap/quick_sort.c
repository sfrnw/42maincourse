/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:17:09 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/29 19:19:46 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quick_sorting(t_node **stack_a, t_node **stack_b, int size)
{
    int pivot;
    int pushed;
	int	i;

    if (size <= 3)
    {
        sort_small(stack_a, size);
        return;
    }
    if (is_sorted(*stack_a, size))
        return;

    pivot = approximate_pivot(*stack_a, size);
    pushed = 0;
	i = size;

    while (i > 0)
    {
        if ((*stack_a)->value < pivot)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
            ra(stack_a);
        i--;
    }
    // Sort upper part (elements >= pivot)
    quick_sorting(stack_a, stack_b, size - pushed);

    // Sort lower part (elements < pivot)
    quick_sorting(stack_b, stack_a, pushed);

    // Move all elements from B to A
    i = pushed;
    while (i > 0)
    {
        pa(stack_b, stack_a);
        i--;
    }
}


// Approximate pivot (choose middle element for simplicity)
int approximate_pivot(t_node *stack, int size)
{
    int i;
    t_node *current = stack;

    for (i = 0; i < size / 2 && current; i++)
    {
        current = current->next;
    }
    return current ? current->value : stack->value;
}






	
void sort_small_3(t_node **stack)
{
	int first;
	int second;
	int third;
	
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first >= second && second >= third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first >= second && second < third && first >= third)
		ra(stack);
	else if (first >= second && second < third && first < third)	
		sa(stack);
	else if (first < second && second >= third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second >= third && first >= third)
		ra(stack);
}

void sort_small(t_node **stack, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
    }
	else
	{
		sort_small_3(stack);
	}
}

// int	partition(t_node **stack_a, t_node **stack_b, int pivot, int size)
// {
// int pushed;
//     int i;

//     pushed = 0;
//     i = 0;
//     while (i < size - 1)  // Don't process the last element (pivot)
//     {
//         if ((*stack_a)->value < pivot)
//         {
//             pb(stack_a, stack_b);
//             pushed++;
//         }
//         else
//         {
//             ra(stack_a);
//         }
//         i++;
//     }
//     return pushed;
// }
