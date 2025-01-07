/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:26:59 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/07 20:11:13 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	handle_arguments(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**args;
	int		j;

	i = 0;
	while (++i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			return (0);
		j = 0;
		while (args[j])
		{
			if (!process_argument(args[j], stack_a))
			{
				free_stack(stack_a);
				free_split(args);
				return (0);
			}
			j++;
		}
		free_split(args);
	}
	return (1);
}

static void	choose_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	start;
	int	end;

	start = 0;
	end = 15;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		ps_more(stack_a, stack_b, &start, &end);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!handle_arguments(argc, argv, &stack_a))
	{
		free_stack(&stack_a);
		print_error();
		return (1);
	}
	size = stack_size(stack_a);
	if (!is_sorted(&stack_a))
		choose_sort(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	return (0);
}
