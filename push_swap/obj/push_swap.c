/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:42:34 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/07 16:16:09 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			handle_error(&stack_a, 1);
		new_node = create_node(ft_atoi(argv[i]));
		if (!new_node)
			handle_error(&stack_a, 3);
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
	{
		handle_error(&stack_a, 4);
		return (1);
	}
	if (has_duplicate(stack_a))
	{
		handle_error(&stack_a, 2);
		return (1);
	}
	stack_b = NULL;
	if (!is_sorted(stack_a))
		turk_sort(&stack_a, &stack_b, &move_count);
	free_stack(&stack_a);
	free_stack(&stack_b);
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