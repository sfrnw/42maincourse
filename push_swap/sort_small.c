/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:53:18 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/03 15:11:05 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_small_a(t_node **stack_a, int size)
{
    if (size <= 1)
        return;
    
    if (size == 2)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a);
        return;
    }
    
    if (size == 3)
    {
        int first = (*stack_a)->value;
        int second = (*stack_a)->next->value;
        int third = (*stack_a)->next->next->value;
        
        if (first > second && second > third)
        {
            sa(stack_a);
            rra(stack_a);
        }
        else if (first > second && second < third && first > third)
            ra(stack_a);
        else if (first > second && second < third && first < third)
            sa(stack_a);
        else if (first < second && second > third && first > third)
            rra(stack_a);
        else if (first < second && second > third && first < third)
        {
            sa(stack_a);
            ra(stack_a);
        }
    }
}
void sort_small_b(t_node **stack_a, t_node **stack_b, int size)
{
    if (size <= 1)
    {
        if (size == 1)
            pa(stack_a, stack_b);
        return;
    }
    
    if (size == 2)
    {
        if ((*stack_b)->value < (*stack_b)->next->value)
            sb(stack_b);
        pa(stack_a, stack_b);
        pa(stack_a, stack_b);
        return;
    }
    
    if (size == 3)
    {
        // Get the values
        int first = (*stack_b)->value;
        int second = (*stack_b)->next->value;
        int third = (*stack_b)->next->next->value;
        
        // Sort stack B in descending order before pushing to A
        if (first < second && second < third)
        {
            sb(stack_b);
            rb(stack_b);
        }
        else if (first < second && second > third && first < third)
            sb(stack_b);
        else if (first > second && second < third && first < third)
            rb(stack_b);
        else if (first < second && second > third && first > third)
            rrb(stack_b);
        else if (first > second && second < third && first > third)
        {
            sb(stack_b);
            rrb(stack_b);
        }
        
        // Push all elements to stack A
        pa(stack_a, stack_b);
        pa(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
}
