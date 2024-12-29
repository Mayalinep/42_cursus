/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:44:24 by mpelage          #+#    #+#             */
/*   Updated: 2024/06/11 15:40:12 by mpelage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printwhat(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_print_char(va_arg(args, int), count);
	else if (c == 's')
		ft_print_str(va_arg(args, char *), count);
	else if (c == 'u')
		ft_print_intup(va_arg(args, int), count);
	else if (c == 'd' || c == 'i')
		ft_print_int(va_arg(args, int), count);
	else if (c == 'p')
		ft_print_ptrfirst(va_arg(args, unsigned long long), count);
	else if (c == 'x' || c == 'X')
		ft_print_hexafirst(va_arg(args, unsigned int), count, c);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	if (!str)
		return (va_end(args), -1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_printwhat(*str, args, &count);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
