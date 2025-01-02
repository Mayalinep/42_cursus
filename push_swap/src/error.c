/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:39:54 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/30 15:21:58 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    print_error(char *str)
{
    ft_printf("Error\n");
    ft_printf("%s\n", str);
}

void free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = *stack;       
        *stack = (*stack)->next; 
        free(temp);
    }
    *stack = NULL;
}
