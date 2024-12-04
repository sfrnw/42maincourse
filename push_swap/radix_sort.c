/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:04 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/04 15:46:44 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// void debug_print_stack(t_node *stack, const char *name)
// {
//     printf("Stack %s: ", name);
//     while (stack)
//     {
//         printf("%d ", stack->value);
//         stack = stack->next;
//     }
//     printf("\n");
// }


// static int get_max_value(t_node *stack)
// {
//     if (!stack)
//     {
//         // ft_putendl_fd("Error: stack is empty", 2);
//         return 0;
//     }
//     int max_value = stack->value;
//     while (stack)
//     {
//         if (stack->value > max_value)
//             max_value = stack->value;
//         stack = stack->next;
//     }
//     return max_value;
// }



static int get_max_bits(t_node *stack)
{
    int max = 0;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    int bits = 0;
    while (max > 0)
    {
        bits++;
        max >>= 1;
    }
    return bits;
}

static void push_based_on_bit(t_node **stack_a, t_node **stack_b, int bit, int *move_count)
{
    int size = get_stack_size(*stack_a);
    for (int i = 0; i < size; i++)
    {
        if (((*stack_a)->value >> bit) & 1)
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

static void empty_stack_b(t_node **stack_a, t_node **stack_b, int *move_count)
{
    while (*stack_b)
    {
        pa(stack_a, stack_b);
        (*move_count)++;
    }
}

void radix_sort(t_node **stack_a, t_node **stack_b, int *move_count)
{
    int max_bits = get_max_bits(*stack_a);

    for (int bit = 0; bit < max_bits; bit++)
    {
        push_based_on_bit(stack_a, stack_b, bit, move_count);
        empty_stack_b(stack_a, stack_b, move_count);
    }
}

