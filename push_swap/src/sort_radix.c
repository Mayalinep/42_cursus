/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:56:32 by maya              #+#    #+#             */
/*   Updated: 2025/01/03 18:00:07 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
    int max_bits;
    int i;
    int j;
    int num;

    max_bits = 0;
    i = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = (*stack_a)->data;
            if ((num >> i) & 1)
                rotate_a(stack_a, 0);
            else
                push_b(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            push_a(stack_a, stack_b);
        i++;
    }
}
