/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:53:58 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/07 15:56:58 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	has_duplicate(t_node *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

void	handle_error(t_node **stack, int i)
{
	free_stack(stack);
	if (i == 1)
	{
		ft_putendl_fd("Error: not a number", 2);
		return ;
	}
	if (i == 2)
	{
		ft_putendl_fd("Error: duplicate", 2);
		return ;
	}
	if (i == 3)
	{
		ft_putendl_fd("Error: node creation", 2);
		return ;
	}
	if (i == 4)
	{
		ft_putendl_fd("Error: no stack", 2);
		return ;
	}
}
