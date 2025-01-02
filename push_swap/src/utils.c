/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:26:54 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/30 15:22:57 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack  *create_node(int data)
{
    t_stack  *new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

void    add_to_stack(t_stack **stack, int data)
{
    t_stack  *new_node;
    t_stack  *current;

    new_node = create_node(data);
    if (!new_node)
        return ;
    if (*stack == NULL)
    {
        *stack = new_node;
        return ;
    }
    current = *stack;
    while (current->next)
        current = current->next;
    current->next = new_node;    
}

int is_duplicate(t_stack *stack, int data)
{
    while(stack)
    {
        if (stack->data == data)
            return (1);
        stack = stack->next;
    }
    return (0);
}
