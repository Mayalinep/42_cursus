/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:11:27 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 15:15:25 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	current = (*stack);
	while (current->data < current->next->data)
	{
		if (current->next->next == NULL)
			return (1);
		current = current->next;
	}
	return (0);
}

void	push_to_next(t_stack **stack_a, t_stack **stack_b)
{
	int		mid;
	t_stack	*t;

	while (*stack_b)
	{
		t = find_max_node(stack_b);
		mid = is_half_in_stack(stack_b, t->data, stack_size(*stack_b) / 2);
		while ((*stack_b)->data != t->data)
		{
			if (mid == 1)
				rotate_b(stack_b, 0);
			else
				reverse_rotate_b(stack_b, 0);
		}
		push_a(stack_a, stack_b);
	}
}

void	ps_more(t_stack **stack_a, t_stack **stack_b, int *start, int *end)
{
	int	len;

	len = stack_size(*stack_a);
	assign_indexes(stack_a, len);
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
	push_to_next(stack_a, stack_b);
}
