/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:08:56 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/17 12:10:31 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	freegrid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

void	destroy_all(t_game *game)
{
	if (game->p != NULL)
		mlx_destroy_image(game->mlx_ptr, game->p);
	if (game->c != NULL)
		mlx_destroy_image(game->mlx_ptr, game->c);
	if (game->w != NULL)
		mlx_destroy_image(game->mlx_ptr, game->w);
	if (game->f != NULL)
		mlx_destroy_image(game->mlx_ptr, game->f);
	if (game->e != NULL)
		mlx_destroy_image(game->mlx_ptr, game->e);
	if (game->win_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr != NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

void	error_solong(char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	if (game->map.grid != NULL)
		freegrid(game->map.grid);
	if (game->map.grid_clone != NULL)
		freegrid(game->map.grid_clone);
	if (game->map.grid_third != NULL)
		freegrid(game->map.grid_third);
	destroy_all(game);
	exit(EXIT_FAILURE);
}

void	init_value(t_game *game)
{
	game->map.grid = NULL;
	game->map.grid_clone = NULL;
	game->map.grid_third = NULL;
	game->map.img_size.x = 32;
	game->map.img_size.y = 32;
	game->moves = 0;
	game->c = NULL;
	game->f = NULL;
	game->e = NULL;
	game->w = NULL;
	game->p = NULL;
	game->win_ptr = NULL;
	game->mlx_ptr = NULL;
}

void	game_over(t_game *game)
{
	if (game->map.grid != NULL)
		freegrid(game->map.grid);
	if (game->map.grid_clone != NULL)
		freegrid(game->map.grid_clone);
	if (game->map.grid_third != NULL)
		freegrid(game->map.grid_third);
	destroy_all(game);
	exit(EXIT_SUCCESS);
}
