/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:47:45 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 15:58:24 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
	temp = NULL;
}

void	free_resources(char **split_args, t_stack **stack_a, t_stack **stack_b,
		int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (split_args[i])
		{
			free(split_args[i]);
			i++;
		}
		free(split_args);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
		if (split_args != NULL)
			free(split_args);
	}
}

void	error_message(char *str, t_stack **stack_a, char **split_args)
{
	int	i;

	ft_printf("Error.\n%s", str);
	free_stack(stack_a);
	i = 0;
	if (split_args != NULL)
	{
		while (split_args[i])
		{
			free(split_args[i]);
			i++;
		}
		free(split_args);
		free_stack(stack_a);
	}
	exit(EXIT_FAILURE);
}
