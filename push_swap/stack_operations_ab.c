/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_ab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:21:15 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/04 13:39:14 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

// void ss(t_node **stack_a, t_node **stack_b)
// {
//     t_node *first;
//     t_node *second;
// 	if (!stack_a || !stack_b)
// 		return;
//     // Swap stack_a
//     if (*stack_a && (*stack_a)->next)
//     {
//         first = *stack_a;
//         second = first->next;
//         first->next = second->next;
//         second->next = first;
//         *stack_a = second;
//     }

//     // Swap stack_b
//     if (*stack_b && (*stack_b)->next)
//     {
//         first = *stack_b;
//         second = first->next;
//         first->next = second->next;
//         second->next = first;
//         *stack_b = second;
//     }

//     write(1, "ss\n", 3);
// }

// void rr(t_node **stack_a, t_node **stack_b)
// {
//     t_node *first;
//     t_node *last;
// 	if (!stack_a || !stack_b)
// 		return;
//     if (*stack_a && (*stack_a)->next)
//     {
//         first = *stack_a;
//         last = *stack_a;
//         while (last->next)
//             last = last->next;
//         *stack_a = first->next;
//         last->next = first;
//         first->next = NULL;
//     }
//     if (*stack_b && (*stack_b)->next)
//     {
//         first = *stack_b;
//         last = *stack_b;
//         while (last->next)
//             last = last->next;
//         *stack_b = first->next;
//         last->next = first;
//         first->next = NULL;
//     }

//     write(1, "rr\n", 3);
// }

// void rrr(t_node **stack_a, t_node **stack_b)
// {
//     t_node *last;
//     t_node *second_last;
// 	if (!stack_a || !stack_b)
// 		return;
//     // Reverse rotate stack_a
//     if (*stack_a && (*stack_a)->next)
//     {
//         if ((*stack_a)->next->next == NULL)
//         {
//             // Swap if only two elements
//             t_node *temp = *stack_a;
//             *stack_a = (*stack_a)->next;
//             (*stack_a)->next = temp;
//             temp->next = NULL;
//         }
//         else
//         {
//             last = *stack_a;
//             second_last = NULL;
//             while (last->next)
//             {
//                 second_last = last;
//                 last = last->next;
//             }
//             last->next = *stack_a;
//             *stack_a = last;
//             second_last->next = NULL;
//         }
//     }

//     // Reverse rotate stack_b
//     if (*stack_b && (*stack_b)->next)
//     {
//         if ((*stack_b)->next->next == NULL)
//         {
//             // Swap if only two elements
//             t_node *temp = *stack_b;
//             *stack_b = (*stack_b)->next;
//             (*stack_b)->next = temp;
//             temp->next = NULL;
//         }
//         else
//         {
//             last = *stack_b;
//             second_last = NULL;
//             while (last->next)
//             {
//                 second_last = last;
//                 last = last->next;
//             }
//             last->next = *stack_b;
//             *stack_b = last;
//             second_last->next = NULL;
//         }
//     }

//     write(1, "rrr\n", 4);
// }
