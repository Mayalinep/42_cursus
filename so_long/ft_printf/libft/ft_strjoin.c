/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:22:53 by mpelage          #+#    #+#             */
/*   Updated: 2024/08/21 10:55:10 by mpelage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	biglen;
	char	*s3;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	biglen = (ft_strlen(s1) + ft_strlen(s2));
	s3 = malloc(sizeof(char) * (biglen + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	s3[i + ft_strlen(s1)] = '\0';
	return (s3);
}
