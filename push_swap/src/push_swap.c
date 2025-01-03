/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:26:59 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/03 19:07:38 by maya             ###   ########.fr       */
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
void choose_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size == 4)
        sort_four(stack_a, stack_b);
    else if (size == 5)
        sort_five(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b, size);
}


int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int size;

    stack_a = NULL;
    stack_b = NULL;

    if (argc < 2)
        return (0); // Aucun paramètre, rien à faire

    if (!handle_arguments(argc, argv, &stack_a))
    {
        free_stack(&stack_a);
        print_error("Invalid arguments"); // Utilisation de ta fonction
        return (1);
    }

    size = stack_size(stack_a); // Obtenir la taille de la pile
    if (!is_sorted(&stack_a))  // Vérifier si la pile est déjà triée
        choose_sort(&stack_a, &stack_b, size);

    free_stack(&stack_a);
    return (0);
}
