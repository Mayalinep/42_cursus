/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:07:53 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/08 16:22:13 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				validate_argument(char *str, t_stack **stack_a,
						char **split_args);
int					is_valid_number(char *str);

void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				rotate_a(t_stack **stack_a, int flag);
void				rotate_b(t_stack **stack_b, int flag);
void				rotate_rr(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate_a(t_stack **stack_a, int flag);
void				reverse_rotate_b(t_stack **stack_b, int flag);
void				reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b);
void				swap_a(t_stack **stack_a, int flag);
void				swap_b(t_stack **stack_b, int flag);
void				swap_ss(t_stack **stack_a, t_stack **stack_b);

void				sort_two(t_stack **stack_a);
void				sort_three(t_stack **stack_a);
void				sort_four(t_stack **stack_a, t_stack **stack_b);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				ps_more(t_stack **stack_a, t_stack **stack_b, int *start,
						int *end);

t_stack				*create_node(int value);
void				init_stack(char *argv, t_stack **stack_a,
						char **split_args);
void				push_swap(t_stack **stack_a, t_stack **stack_b);
void				add_to_stack_back(t_stack **stack, t_stack *new_node);
void				add_to_stack_front(t_stack **stack, t_stack *new_node);
int					stack_size(t_stack *stack);
void				free_stack(t_stack **stack);
void				free_resources(char **split_args, t_stack **stack_a,
						t_stack **stack_b, int argc);
void				error_message(char *str, t_stack **stack_a,
						char **split_args);
t_stack				*find_min_node(t_stack **stack);
t_stack				*find_max_node(t_stack **stack);
int					is_half_in_stack(t_stack **stack, int max, int len);
void				assign_indexes(t_stack **stack_a, int len);
int					is_sorted(t_stack **stack);

#endif
