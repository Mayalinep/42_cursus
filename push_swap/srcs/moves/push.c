/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:01:52 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 15:57:20 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_a))
		return ;
	temp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_printf("pb\n");
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_b))
		return ;
	temp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_printf("pa\n");
}
