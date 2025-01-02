/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:01:22 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/02 11:40:44 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    if (!(*stack_b))
        return ;

    temp = (*stack_b);
    (*stack_b) = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;

    ft_printf("pa\n");
}

void    push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if(!(*stack_a))
        return ;
    
    temp = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
    
    ft_printf("pb\n");
}
