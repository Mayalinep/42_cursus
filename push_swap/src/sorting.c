/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:59:55 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/03 17:32:25 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		swap_a(stack_a, 0);
	}
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && b < c && a < c)
		swap_a(stack_a, 0);
	else if (a > b && b > c)
	{
		swap_a(stack_a, 0);
		reverse_rotate_a(stack_a, 0);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a, 0);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a, 0);
		rotate_a(stack_a, 0);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a, 0);
}

void sort_four(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min;
    int min_value;

    min = find_min(stack_a);
    min_value = min->data;
    if ((*stack_a)->data == min_value)
        push_b(stack_a, stack_b);
    else if ((*stack_a)->next->data == min_value)
    {
        rotate_a(stack_a, 0);
        push_b(stack_a, stack_b);
    }
    else
    {
        while ((*stack_a)->data != min_value)
            reverse_rotate_a(stack_a, 0);
        push_b(stack_a, stack_b);
    }
    if (!is_sorted(stack_a))
        sort_three(stack_a);
    push_a(stack_a, stack_b);
}
void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min;
    int min_value;

    min = find_min(stack_a);
    min_value = min->data;
    if ((*stack_a)->data == min_value)
        push_b(stack_a, stack_b);
    else if ((*stack_a)->next->data == min_value)
    {
        rotate_a(stack_a, 0);
        push_b(stack_a, stack_b);
    }
    else
    {
        while ((*stack_a)->data != min_value)
            reverse_rotate_a(stack_a, 0);
        push_b(stack_a, stack_b);
    }
    if (!is_sorted(stack_a))
        sort_four(stack_a, stack_b);
    push_a(stack_a, stack_b);
}




