/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:41:36 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/03 18:35:22 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
    int             data;
    struct s_stack  *next;
}   t_stack;

void print_error(char *str);

int is_valid_number(const char *str);
int ft_atoi_safe(const char *str, int *error);
int is_duplicate(t_stack *stack, int value);
int handle_arguments(int argc, char **argv, t_stack **stack_a);
int validate_arg(char *arg, int *error);

t_stack *create_node(int data);
void add_to_stack(t_stack **stack, int data);
int stack_size(t_stack *stack);
void free_stack(t_stack **stack);
t_stack *find_min(t_stack **stack);
int is_sorted(t_stack **stack);
int get_position(t_stack **stack, int value);

void sort_two(t_stack **stack_a);
void sort_three(t_stack **stack_a);
void sort_four(t_stack **stack_a, t_stack **stack_b);
void sort_five(t_stack **stack_a, t_stack **stack_b);
void radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

void swap_a(t_stack **stack_a, int flag);
void swap_b(t_stack **stack_b, int flag);
void swap_ss(t_stack **stack_a, t_stack **stack_b);
void push_a(t_stack **stack_a, t_stack **stack_b);
void push_b(t_stack **stack_a, t_stack **stack_b);
void rotate_a(t_stack **stack_a, int flag);
void rotate_b(t_stack **stack_b, int flag);
void rotate_rr(t_stack **stack_a, t_stack **stack_b);
void reverse_rotate_a(t_stack **stack_a, int flag);
void reverse_rotate_b(t_stack **stack_b, int flag);
void reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b);

#endif

