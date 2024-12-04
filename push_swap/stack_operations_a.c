/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:21:15 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/04 14:03:47 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

// void	pa(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*top_b;

// 	if (*stack_b == NULL)
// 		return ;
// 	top_b = pop(stack_b);
// 	push(stack_a, top_b);
// 	write(1, "pa\n", 3);
// }

void pa(t_node **stack_a, t_node **stack_b)
{
    if (*stack_b == NULL)
        return;
    t_node *top_b = pop(stack_b);
    push(stack_a, top_b);
    write(1, "pa\n", 3);
}

void	ra(t_node **stack_a)
{	
	if (!*stack_a || !(*stack_a)->next)
        return;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

// void pa(t_node **stack_a, t_node **stack_b)
// {
//     t_node *top_b;

//     if (*stack_b == NULL)
//         return;

//     top_b = *stack_b;
//     *stack_b = (*stack_b)->next;
//     top_b->next = *stack_a;
//     *stack_a = top_b;

//     write(1, "pa\n", 3);
// }


// void ra(t_node **stack_a)
// {
//     t_node *first;
//     t_node *last;

//     if (!*stack_a || !(*stack_a)->next)
//         return;

//     first = *stack_a;
//     last = *stack_a;

//     while (last->next)
//         last = last->next;

//     *stack_a = first->next;
//     last->next = first;
//     first->next = NULL;

//     write(1, "ra\n", 3);
// }




// void rra(t_node **stack_a)
// {
//     t_node *last;
//     t_node *second_last;

//     if (!*stack_a || !(*stack_a)->next)
//         return;

//     last = *stack_a;
//     second_last = NULL;
//     while (last->next)
//     {
//         second_last = last;
//         last = last->next;
//     }

//     last->next = *stack_a;
//     *stack_a = last;
//     second_last->next = NULL;

//     write(1, "rra\n", 4);
// }

