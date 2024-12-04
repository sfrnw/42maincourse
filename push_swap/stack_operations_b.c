/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:21:15 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/04 13:40:27 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*top_a;

	if (*stack_a == NULL)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	push(stack_b, top_a);
	write(1, "pb\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

// void sb(t_node **stack_b)
// {
//     t_node *first;
//     t_node *second;

//     if (!*stack_b || !(*stack_b)->next)
//         return;

//     first = *stack_b;
//     second = first->next;
//     first->next = second->next;
//     second->next = first;
//     *stack_b = second;

//     write(1, "sb\n", 3);
// }

// void pb(t_node **stack_a, t_node **stack_b)
// {
//     t_node *top_a;

//     if (*stack_a == NULL)
//         return;

//     top_a = *stack_a;
//     *stack_a = (*stack_a)->next;

//     // Incorporating push functionality
//     top_a->next = *stack_b;
//     *stack_b = top_a;

//     write(1, "pb\n", 3);
// }

// void rb(t_node **stack_b)
// {
//     t_node *first;
//     t_node *last;

//     if (!stack_b || !*stack_b || !(*stack_b)->next)
//         return;

//     first = *stack_b;
//     last = *stack_b;

//     while (last->next)
//         last = last->next;

//     *stack_b = first->next;
//     last->next = first;
//     first->next = NULL;

//     write(1, "rb\n", 3);
// }

// void rrb(t_node **stack_b)
// {
//     t_node *last;
//     t_node *second_last;

//     if (!stack_b || !*stack_b || !(*stack_b)->next)
//         return;
//     if ((*stack_b)->next->next == NULL)
//     {
//         t_node *temp = *stack_b;
//         *stack_b = (*stack_b)->next;
//         (*stack_b)->next = temp;
//         temp->next = NULL;
//     }
//     else
//     {
//         last = *stack_b;
//         second_last = NULL;
//         while (last->next)
//         {
//             second_last = last;
//             last = last->next;
//         }
//         last->next = *stack_b;
//         *stack_b = last;
//         second_last->next = NULL;
//     }
//     write(1, "rrb\n", 4);
// }
