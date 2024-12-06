/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:42:34 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/06 17:04:59 by asafrono         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		move_count;

	move_count = 0;
	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	if (!is_sorted(stack_a))
		turk_sort(&stack_a, &stack_b, &move_count);
	ft_putendl_fd("\n Stack A:", 1);
	print_stack(stack_a);
	ft_putendl_fd("\n Stack B:", 1);
	print_stack(stack_b);
	ft_putstr_fd("Total moves: \n", 1);
	ft_putnbr_fd(move_count, 1);
	free_stack (&stack_a);
	free_stack (&stack_b);
	return (0);
}

// 	ft_putendl_fd("\n Stack A:", 1);
// 	print_stack(stack_a);
// 	ft_putendl_fd("\n Stack B:", 1);
// 	print_stack(stack_b);
// 	ft_putstr_fd("Total moves: \n", 1);
// 	ft_putnbr_fd(move_count, 1);

//  bubble_sorting(&stack_a, &stack_b, size);
//radix_sort(&stack_a, &stack_b, &move_count);