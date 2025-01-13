/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:12:41 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 16:09:44 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!*str)
			return (0);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > 2147483647))
			return (0);
		if ((sign == -1 && res > 2147483648))
			return (0);
		str++;
	}
	return (1);
}

void	validate_argument(char *str, t_stack **stack_a, char **split_args)
{
	if (!is_valid_number(str))
		error_message("Parameter isn't an integer or a number.\n", stack_a,
			split_args);
	init_stack(str, stack_a, split_args);
}

int	main(int argc, char **argv)
{
	char	**split_args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		index;

	index = 0;
	stack_a = NULL;
	stack_b = NULL;
	split_args = NULL;
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		while (split_args[index])
			validate_argument(split_args[index++], &stack_a, split_args);
	}
	else if (argc > 2)
	{
		while (argv[++index])
			validate_argument(argv[index], &stack_a, split_args);
	}
	if (!is_sorted(&stack_a))
		push_swap(&stack_a, &stack_b);
	free_resources(split_args, &stack_a, &stack_b, argc);
	exit(EXIT_SUCCESS);
	return (0);
}
