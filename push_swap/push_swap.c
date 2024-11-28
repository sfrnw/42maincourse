/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:49:06 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/27 17:24:08 by asafrono         ###   ########.fr       */
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
	t_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	handle_error(t_node **stack)
{
	free_stack(stack);
	ft_putendl_fd("Error", 2);
	exit(1);
}

t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	int		value;
	t_node	*new_node;

	stack_a = NULL;
	i = argc;
	while (--i > 0)
	{
		if (!is_valid_number(argv[i]))
			handle_error(&stack_a);
		value = ft_atoi(argv[i]);
		new_node = create_node(value);
		if (!new_node)
			handle_error(&stack_a);
		push(&stack_a, new_node);
	}
	return (stack_a);
}

int	is_sorted(t_node *stack)
{
	t_node	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
