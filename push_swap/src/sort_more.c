/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:10:34 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/07 19:37:50 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	index_zero(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
}

void	init_index(t_stack **stack_a, int size)
{
	t_stack	*temp;
	t_stack	*current;
	int		min;
	int		i;

	index_zero(stack_a);
	i = 1;
	while (size > 0)
	{
		min = INT_MAX;
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
		size--;
	}
}

void	ps_next(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		half;
	t_stack	*t;

	t = NULL;
	while (*stack_b)
	{
		t = find_max(stack_b);
		half = find_half(stack_b, t->data, (size / 2));
		while ((*stack_b)->data != t->data)
		{
			if (half == 1)
				rotate_b(stack_b, 0);
			else
				reverse_rotate_b(stack_b, 0);
		}
		push_a(stack_a, stack_b);
	}
}

void	ps_more(t_stack **stack_a, t_stack **stack_b, int *start, int *end)
{
	int	size;

	size = stack_size(*stack_a);
	init_index(stack_a, size);
	while (*stack_a)
	{
		if ((*stack_a)->index <= (*start))
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b, 0);
			(*start)++;
			(*end)++;
		}
		else if ((*stack_a)->index > (*start) && (*stack_a)->index < (*end))
		{
			push_b(stack_a, stack_b);
			(*start)++;
			(*end)++;
		}
		else if ((*stack_a)->index >= (*end))
			rotate_a(stack_a, 0);
	}
	ps_next(stack_a, stack_b, size);
}
