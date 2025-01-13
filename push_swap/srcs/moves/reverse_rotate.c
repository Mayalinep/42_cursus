/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:00:26 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 15:57:30 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_a(t_stack **stack_a, int flag)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	second_last = NULL;
	last = *stack_a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	second_last->next = NULL;
	if (flag == 0)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b, int flag)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	second_last = NULL;
	last = *stack_b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	second_last->next = NULL;
	if (flag == 0)
		ft_printf("rrb\n");
}

void	reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	int	flag;

	flag = 1;
	reverse_rotate_a(stack_a, flag);
	reverse_rotate_b(stack_b, flag);
	ft_printf("rrr\n");
}
