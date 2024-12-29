/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:16:18 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/18 08:37:29 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	i--;
	if (name[i] == 'r')
		i--;
	else
		return (0);
	if (name[i] == 'e')
		i--;
	else
		return (0);
	if (name[i] == 'b')
		i--;
	else
		return (0);
	if (name[i] == '.' && name[i - 1] != '\0')
		return (1);
	return (0);
}

int	check_line_format(char *getmap, t_game *game)
{
	int	i;

	i = 0;
	if (getmap[0] == '\n')
		return (1);
	while (getmap[i])
	{
		if (getmap[i] == '\n' && getmap[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	is_wrong_data(char data, char *allowed)
{
	int	i;

	i = 0;
	while (allowed[i])
	{
		if (data == allowed[i])
			return (1);
		i++;
	}
	return (0);
}

void	init_elem(t_game *game)
{
	game->map.c = 0;
	game->map.p = 0;
	game->map.e = 0;
}

void	check_elem(t_game *game)
{
	if (game->map.c < 1 || game->map.e < 1 || game->map.p < 1)
		error_solong("At least 1 exit, 1 player or 1 item is missing", game);
	if (game->map.p > 1 && game->map.e > 1)
		error_solong("There is more than 1 player & 1 exit in this map", game);
	else if (game->map.p > 1)
		error_solong("There is more than 1 player in this map", game);
	else if (game->map.e > 1)
		error_solong("There is more than 1 exit in this map", game);
}
