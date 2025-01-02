/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:01:14 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/02 12:51:51 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **stack_a, int flag)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
	{
		last = last->next;
	}
	last->next = temp;
	temp->next = NULL;
	if (flag == 0)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b, int flag)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = *stack_b;
	while (last->next)
	{
		last = last->next;
	}
	last->next = temp;
	temp->next = NULL;
	if (flag == 0)
		ft_printf("rb\n");
}

void rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
    int flag;

    flag = 1;

    rotate_a(stack_a, flag); 
    rotate_b(stack_b, flag);

    ft_printf("rr\n");
}
