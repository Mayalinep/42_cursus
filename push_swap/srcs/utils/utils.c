/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:25:03 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 15:58:50 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reset_indexes(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
}

void	assign_indexes(t_stack **stack_a, int len)
{
	t_stack	*temp;
	t_stack	*current;
	int		min;
	int		i;

	reset_indexes(stack_a);
	i = 1;
	while (len > 0)
	{
		min = INT32_MAX;
		current = *stack_a;
		while (current)
		{
			if (current->data < min && current->index == 0)
			{
				min = current->data;
				temp = current;
			}
			current = current->next;
		}
		temp->index = i;
		i++;
		len--;
	}
}

t_stack	*find_min_node(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*min_node;
	int		min;

	min = INT32_MAX;
	temp = *stack;
	min_node = NULL;
	while (temp)
	{
		if (temp->data < min)
		{
			min = temp->data;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

t_stack	*find_max_node(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*max_node;
	int		max;

	max = INT32_MIN;
	temp = *stack;
	max_node = NULL;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}

int	is_half_in_stack(t_stack **stack, int max, int len)
{
	t_stack	*current;

	current = *stack;
	while (len > 0 && current)
	{
		if (current->data == max)
			return (1);
		current = current->next;
		len--;
	}
	return (0);
}
