/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:42:34 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/04 17:33:30 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	if (!stack)
	{
		ft_putendl_fd("(empty)", 1);
		return ;
	}
	while (stack)
	{
		ft_putnbr_fd(stack->value, 1);
		ft_putchar_fd(' ', 1);
		stack = stack->next;
	}
	ft_putchar_fd('\n', 1);
}

int	get_stack_size(t_node *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	int		move_count;

	move_count = 0;
	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	size = get_stack_size(stack_a);
	if (!is_sorted(stack_a))
	{
		if (size <= 3)
			sort_small(&stack_a, size);
		else
			radix_sort(&stack_a, &stack_b, &move_count);
	}
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

	// ft_putendl_fd("\n Stack A:", 1);
	// print_stack(stack_a);
	// ft_putendl_fd("\n Stack B:", 1);
	// print_stack(stack_b);
	// ft_putstr_fd("Total moves: \n", 1);
	// ft_putnbr_fd(move_count, 1);

//  bubble_sorting(&stack_a, &stack_b, size);