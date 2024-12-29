/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 05:49:48 by mpelage          #+#    #+#             */
/*   Updated: 2024/06/11 11:58:15 by mpelage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *s, int *count)
{
	int		i;
	char	*empty;

	i = 0;
	empty = "(null)";
	if (!s)
	{
		while (empty[i])
		{
			ft_putchar_fd(empty[i], 1);
			i++;
		}
	}
	else
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	(*count) += i;
}

void	ft_print_int(int a, int *count)
{
	char	*s;
	int		i;

	s = (ft_itoa(a));
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	(*count) += i;
	free(s);
}

void	ft_print_char(int c, int *count)
{
	ft_putchar_fd(c, 1);
	(*count)++;
}

void	ft_print_intup(unsigned int a, int *count)
{
	if (a >= 10)
		ft_print_intup((a / 10), count);
	ft_putchar_fd((a % 10 + '0'), 1);
	(*count)++;
}
