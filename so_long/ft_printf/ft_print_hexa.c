/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:08:08 by mpelage          #+#    #+#             */
/*   Updated: 2024/06/10 20:40:43 by mpelage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_hexa(unsigned int a)
{
	int	i;

	i = 0;
	while (a != 0)
	{
		a /= 16;
		i++;
	}
	return (i);
}

static void	ft_print_hexa(unsigned int a, char c)
{
	if (a >= 16)
	{
		ft_print_hexa((a / 16), c);
		ft_print_hexa((a % 16), c);
	}
	else
	{
		if (a < 10)
			ft_putchar_fd((a + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((a - 10 + 'a'), 1);
			else if (c == 'X')
				ft_putchar_fd((a - 10 + 'A'), 1);
		}
	}
}

void	ft_print_hexafirst(unsigned int a, int *count, char c)
{
	if (a == 0)
	{
		write (1, "0", 1);
		(*count)++;
	}
	else
	{
		ft_print_hexa(a, c);
		(*count) += ft_len_hexa(a);
	}
}
