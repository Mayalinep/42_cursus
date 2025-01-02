/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:25:20 by mpelage          #+#    #+#             */
/*   Updated: 2024/06/11 11:55:51 by mpelage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_sixteen(uintptr_t a)
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

static void	ft_print_ptr(uintptr_t a)
{
	if (a >= 16)
	{
		ft_print_ptr((a / 16));
		ft_print_ptr((a % 16));
	}
	else
	{
		if (a < 10)
			ft_putchar_fd((a + '0'), 1);
		else
			ft_putchar_fd((a - 10 + 'a'), 1);
	}
}

void	ft_print_ptrfirst(unsigned long long a, int *count)
{
	if (a == 0)
	{
		write (1, "(nil)", 5);
		(*count) += 5;
	}
	else
	{
		write (1, "0x", 2);
		(*count) += 2;
		ft_print_ptr(a);
		(*count) += ft_len_sixteen(a);
	}
}
