/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:26:59 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/30 16:22:44 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int handle_arguments(int argc, char **argv, t_stack **stack_a)
{
    int i;
    int error;
    int data;

    i = 0;
    while (++i < argc)
    {
        error = 0;
        if (!validate_arg(argv[i], &error))
        {
            print_error("Invalid argument");
            free_stack(stack_a);
            return (0);
        }
        data = ft_atoi_safe(argv[i], &error);
        if (error || is_duplicate(*stack_a, data))
        {
            print_error("Duplicate or out-of-range value");
            free_stack(stack_a);
            return (0);
        }
        add_to_stack(stack_a, data);
    }
    return (1);
}
void print_stack(t_stack *stack)
{
    while (stack)
    {
        ft_printf("%d\n", stack->data);
        stack = stack->next;
    }
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    
    if (argc < 2)
    {
        print_error("Not enough arguments");
        return (1);
    }
    if (!handle_arguments(argc, argv, &stack_a))
        return (1);
    print_stack(stack_a);
    free_stack(&stack_a);
    return (0);
}
