/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 05:51:21 by mpelage          #+#    #+#             */
/*   Updated: 2024/06/10 20:29:25 by mpelage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_printwhat(char c, va_list args, int *count);
void	ft_print_str(char *s, int *count);
void	ft_print_int(int a, int *count);
void	ft_print_char(int c, int *count);
void	ft_print_intup(unsigned int a, int *count);
void	ft_print_hexafirst(unsigned int a, int *count, char c);
void	ft_print_ptrfirst(unsigned long long a, int *count);

#endif
