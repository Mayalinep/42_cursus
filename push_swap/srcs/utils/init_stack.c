/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:46:30 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 15:58:36 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	number_in_stack(t_stack *stack_a, int num)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->data == num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	init_stack(char *argv, t_stack **stack_a, char **split_args)
{
	static t_stack	*temp;
	int				num;

	num = ft_atoi(argv);
	if (number_in_stack(*stack_a, num))
		error_message("There is a parameter twice.", stack_a, split_args);
	temp = create_node(num);
	if (!temp)
		error_message("Failed to create new node.", stack_a, split_args);
	add_to_stack_back(stack_a, temp);
}
