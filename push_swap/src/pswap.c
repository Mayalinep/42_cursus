/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:01:22 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/03 18:53:14 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!(*stack_b))
        return ;

    tmp = (*stack_b);
    (*stack_b) = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;

    ft_printf("pa\n");
}

void    push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!(*stack_a))
        return ;

    tmp = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;

    ft_printf("pb\n");
}
