/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:49:06 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 14:50:02 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	handle_error(t_node **stack)
{
	free_stack(stack);
	ft_putendl_fd("Error", 2);
	return ;
}

t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	t_node	*last;
	t_node	*new_node;

	stack_a = NULL;
	i = 0;
	while (++i < argc)
	{
		if (!is_valid_number(argv[i]))
			handle_error(&stack_a);
		new_node = create_node(ft_atoi(argv[i]));
		if (!new_node)
			handle_error(&stack_a);
		if (stack_a == NULL)
			stack_a = new_node;
		else
		{
			last = stack_a;
			while (last->next)
				last = last->next;
			last->next = new_node;
		}
	}
	return (stack_a);
}

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
