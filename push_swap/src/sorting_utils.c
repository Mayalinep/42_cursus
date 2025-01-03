/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:00:19 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/03 18:20:44 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *find_min(t_stack **stack)
{
    t_stack *current = *stack;
    t_stack *min = current;

    while (current)
    {
        if (current->data < min->data)
            min = current;
        current = current->next;
    }
    return min;
}
int stack_size(t_stack *stack)
{
    int size = 0;

    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

int is_sorted(t_stack **stack)
{
    t_stack *current = *stack;

    while (current && current->next)
    {
        if (current->data > current->next->data)
            return 0;
    current = current->next;
    }
    return 1;
}

