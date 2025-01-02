/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:41:36 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/02 15:03:33 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void				print_error(char *str);
void				free_stack(t_stack **stack);

t_stack				*create_node(int data);
void				add_to_stack(t_stack **stack, int data);
int					is_duplicate(t_stack *stack, int data);

int					is_valid_number(const char *str);
int					ft_atoi_safe(const char *str, int *error);
int					validate_arg(char *arg, int *error);

int					handle_arguments(int argc, char **argv, t_stack **stack_a);

void				swap_a(t_stack **stack_a, int flag);
void				swap_b(t_stack **stack_b, int flag);
void				swap_ss(t_stack **stack_a, t_stack **stack_b);
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				rotate_a(t_stack **stack_a, int flag);
void				rotate_b(t_stack **stack_b, int flag);
void				rotate_rr(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate_a(t_stack **stack_a, int flag);
void				reverse_rotate_b(t_stack **stack_b, int flag);
void				reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b);

void				sort_two(t_stack **stack_a);

#endif