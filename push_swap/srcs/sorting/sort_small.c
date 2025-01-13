/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:07:09 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 15:58:02 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_two(t_stack **stack_a)
{
	int		first;
	int		last;
	t_stack	*temp;

	temp = (*stack_a);
	first = temp->data;
	temp = temp->next;
	last = temp->data;
	if (first > last)
		swap_a(stack_a, 0);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	last;
	int	mid;

	first = (*stack_a)->data;
	mid = (*stack_a)->next->data;
	last = (*stack_a)->next->next->data;
	if (mid > first && mid > last && last > first)
	{
		swap_a(stack_a, 0);
		rotate_a(stack_a, 0);
	}
	if (first > mid && mid < last && last > first)
		swap_a(stack_a, 0);
	if (first > mid && mid < last && last < first)
		rotate_a(stack_a, 0);
	if (mid > last && mid > first && last < first)
		reverse_rotate_a(stack_a, 0);
	if (first > mid && mid > last && first > last)
	{
		rotate_a(stack_a, 0);
		swap_a(stack_a, 0);
	}
	return ;
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		min_nbr;

	min = find_min_node(stack_a);
	min_nbr = min->data;
	if ((*stack_a)->data == min_nbr)
		push_b(stack_a, stack_b);
	else if ((*stack_a)->next->data == min_nbr)
	{
		rotate_a(stack_a, 0);
		push_b(stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->data != min_nbr)
			reverse_rotate_a(stack_a, 0);
		push_b(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		min_nbr;

	min = find_min_node(stack_a);
	min_nbr = min->data;
	if ((*stack_a)->data == min_nbr)
		push_b(stack_a, stack_b);
	else if ((*stack_a)->next->data == min_nbr)
	{
		rotate_a(stack_a, 0);
		push_b(stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->data != min_nbr)
			reverse_rotate_a(stack_a, 0);
		push_b(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	start;
	int	end;
	int	len;

	len = stack_size(*stack_a);
	start = 0;
	end = 15;
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else if (len > 3)
		ps_more(stack_a, stack_b, &start, &end);
}
