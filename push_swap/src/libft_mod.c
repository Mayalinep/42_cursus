/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:55:55 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/07 20:14:39 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi_safe(const char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*error = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)result * sign);
}

int	validate_arg(char *arg, int *error)
{
	if (!is_valid_number(arg))
	{
		*error = 1;
		return (0);
	}
	if (ft_atoi_safe(arg, error) == 0 && *error)
		return (0);
	return (1);
}

int	process_argument(char *arg, t_stack **stack_a)
{
	int	error;
	int	data;

	error = 0;
	if (!validate_arg(arg, &error))
		print_error();
	data = ft_atoi_safe(arg, &error);
	if (error || is_duplicate(*stack_a, data))
		print_error();
	add_to_stack(stack_a, data);
	return (1);
}
