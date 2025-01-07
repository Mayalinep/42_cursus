/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:00:19 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/07 18:55:56 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_min(t_stack **stack)
{
	t_stack	*current;
	t_stack	*min;

	current = *stack;
	min = current;
	while (current)
	{
		if (current->data < min->data)
			min = current;
		current = current->next;
	}
	return (min);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
