/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:34:17 by mpelage          #+#    #+#             */
/*   Updated: 2024/05/31 16:18:15 by mpelage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(char *)s != (char)c)
	{
		if (*(char *)s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
