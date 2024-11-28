/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:42:34 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/27 18:11:30 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->value, 1);
		ft_putchar_fd(' ', 1);
		stack = stack->next;
	}
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	ft_putendl_fd("Initial stack:", 1);
	print_stack(stack_a);
	if (!is_sorted(stack_a))
		bubble_sorting(&stack_a, &stack_b);
	ft_putendl_fd("\nSorted stack:", 1);
	print_stack(stack_a);
	free_stack (&stack_a);
	free_stack (&stack_b);
	return (0);
}
