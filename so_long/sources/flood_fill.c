/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:10:01 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/17 12:10:28 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill_collectables(char **grid, t_vector pos, t_game *game)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (x < 0 || y < 0 || y >= game->map.map_size.y
		|| x >= game->map.map_size.x)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'E' || grid[y][x] == 'X')
		return ;
	grid[y][x] = 'X';
	flood_fill_collectables(grid, (t_vector){x, y - 1}, game);
	flood_fill_collectables(grid, (t_vector){x, y + 1}, game);
	flood_fill_collectables(grid, (t_vector){x - 1, y}, game);
	flood_fill_collectables(grid, (t_vector){x + 1, y}, game);
}

void	flood_fill_exit(char **grid, t_vector pos, t_game *game)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (x < 0 || y < 0 || y >= game->map.map_size.y
		|| x >= game->map.map_size.x)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'X')
		return ;
	grid[y][x] = 'X';
	flood_fill_exit(grid, (t_vector){x, y - 1}, game);
	flood_fill_exit(grid, (t_vector){x, y + 1}, game);
	flood_fill_exit(grid, (t_vector){x - 1, y}, game);
	flood_fill_exit(grid, (t_vector){x + 1, y}, game);
}

void	flood_fill_check(char **grid, char c, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == c)
				error_solong("Unreachable collectible and/or exit", game);
			j++;
		}
		i++;
	}
}

void	total_check(t_game *game)
{
	flood_fill_collectables(game->map.grid_clone, game->map.player_pos, game);
	flood_fill_check(game->map.grid_clone, 'C', game);
	flood_fill_exit(game->map.grid_third, game->map.player_pos, game);
	flood_fill_check(game->map.grid_third, 'E', game);
}
