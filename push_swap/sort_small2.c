// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sort_small2.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/02 16:53:18 by asafrono          #+#    #+#             */
// /*   Updated: 2024/12/03 14:53:27 by asafrono         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void sort_small_3(t_node **stack)
// {
// 	int first;
// 	int second;
// 	int third;
	
// 	first = (*stack)->value;
// 	second = (*stack)->next->value;
// 	third = (*stack)->next->next->value;
// 	if (first >= second && second >= third)
// 	{
// 		sa(stack);
// 		rra(stack);
// 	}
// 	else if (first >= second && second < third && first >= third)
// 		ra(stack);
// 	else if (first >= second && second < third && first < third)	
// 		sa(stack);
// 	else if (first < second && second >= third && first < third)
// 	{
// 		sa(stack);
// 		ra(stack);
// 	}
// 	else if (first < second && second >= third && first >= third)
// 		ra(stack);
// }

// void sort_small(t_node **stack, int size)
// {
// 	if (size <= 1)
// 		return ;
// 	else if (size == 2)
// 	{
// 		if ((*stack)->value > (*stack)->next->value)
// 			sa(stack);
//     }
// 	else if (size == 3)
// 	{
// 		sort_small_3(stack);
// 	}
// }
