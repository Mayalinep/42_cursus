/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:14:48 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/07 18:56:28 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_stack **stack_a, int flag)
{
	t_stack	*before_last;
	t_stack	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	before_last = *stack_a;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (flag == 0)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b, int flag)
{
	t_stack	*before_last;
	t_stack	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	before_last = *stack_b;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
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
