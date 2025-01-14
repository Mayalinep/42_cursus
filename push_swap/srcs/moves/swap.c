/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:53:49 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 16:54:28 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stack **stack_a, int flag)
{
	t_stack	*temp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = (*stack_a);
	(*stack_a) = temp;
	if (flag == 0)
		ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b, int flag)
{
	t_stack	*temp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = (*stack_b);
	(*stack_b) = temp;
	if (flag == 0)
		ft_printf("sb\n");
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	int	flag;

	flag = 1;
	swap_a(stack_a, flag);
	swap_b(stack_b, flag);
	ft_printf("ss\n");
}
