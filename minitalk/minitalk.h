/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:27:27 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/28 18:20:22 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include "gnl/get_next_line.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	free_lst(t_list **lst);

#endif
