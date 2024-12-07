/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:42:34 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/07 19:20:47 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

t_node	*process_argument(char *arg, t_node **stack_a)
{
	t_node	*new_node;
	t_node	*last;

	if (!is_valid_number(arg))
		return (handle_error(stack_a), NULL);
	new_node = create_node(ft_atoi(arg));
	if (!new_node)
		return (handle_error(stack_a), NULL);
	if (*stack_a == NULL)
		*stack_a = new_node;
	else
	{
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	return (*stack_a);
}

t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack_a;
	char	**args;
	int		i;
	int		j;

	i = 0;
	stack_a = NULL;
	while (++i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			return (handle_error(&stack_a), NULL);
		j = -1;
		while (args[++j])
			if (!process_argument(args[j], &stack_a))
				return (ft_free_split(args), NULL);
		ft_free_split(args);
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
	if (has_duplicate(stack_a))
		return (handle_error(&stack_a), 1);
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