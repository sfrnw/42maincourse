/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:49:06 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/04 14:19:52 by asafrono         ###   ########.fr       */
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

void free_node(t_node *node)
{
    if (node)
        free(node);
}

void	free_stack(t_node **stack)
{
    t_node *current;
    t_node *next;

    if (!stack || !*stack)
        return;

    current = *stack;
    while (current)
    {
        next = current->next;
        free_node(current);
        current = next;
    }
    *stack = NULL;
}

void	handle_error(t_node **stack)
{
	free_stack(stack);
	ft_putendl_fd("Error", 2);
	exit(1);
}

// t_node	*parse_arguments(int argc, char **argv)
// {
// 	t_node	*stack_a;
// 	int		i;
// 	int		value;
// 	t_node	*new_node;

// 	stack_a = NULL;
// 	i = argc;
// 	while (--i > 0)
// 	{
// 		if (!is_valid_number(argv[i]))
// 			handle_error(&stack_a);
// 		value = ft_atoi(argv[i]);
// 		new_node = create_node(value);
// 		if (!new_node)
// 			handle_error(&stack_a);
// 		push(&stack_a, new_node);
// 	}
// 	return (stack_a);
// }

t_node *parse_arguments(int argc, char **argv)
{
    t_node *stack_a = NULL;
    int i = 1;  // Start from 1 to skip the program name
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
            handle_error(&stack_a);
        int value = ft_atoi(argv[i]);
        t_node *new_node = create_node(value);
        if (!new_node)
            handle_error(&stack_a);
        
        // Add to the end of the list instead of the beginning
        if (stack_a == NULL)
            stack_a = new_node;
        else
        {
            t_node *last = stack_a;
            while (last->next)
                last = last->next;
            last->next = new_node;
        }
        i++;
    }
    return stack_a;
}

int is_sorted(t_node *stack)
{
    // if (size <= 1)
    //     return 1;
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}
