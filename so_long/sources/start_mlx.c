/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:16:42 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/17 12:17:00 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_image(t_game *game, char *path, void **image)
{
	*image = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&(game->map.img_size.x), &(game->map.img_size.y));
	if (!*image)
		error_solong("Could not load texture into image", game);
}

void	put_image(t_game *game, int y, int x)
{
	if (game->map.grid[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->p,
			x * game->map.img_size.x, y * game->map.img_size.y);
	else if (game->map.grid[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->f,
			x * game->map.img_size.x, y * game->map.img_size.y);
	else if (game->map.grid[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->c,
			x * game->map.img_size.x, y * game->map.img_size.y);
	else if (game->map.grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->w,
			x * game->map.img_size.x, y * game->map.img_size.y);
	else if (game->map.grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->e,
			x * game->map.img_size.x, y * game->map.img_size.y);
}

void	display_map(t_game *game, int y, int x)
{
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			put_image(game, y, x);
			x++;
		}
		y++;
	}
}

void	set_textures(t_game *game)
{
	game->f_path = "./textures/floor.xpm";
	game->e_path = "./textures/exit.xpm";
	game->c_path = "./textures/item.xpm";
	game->p_path = "./textures/player_down.xpm";
	game->w_path = "./textures/wall.xpm";
	load_image(game, game->f_path, &(game->f));
	load_image(game, game->e_path, &(game->e));
	load_image(game, game->c_path, &(game->c));
	load_image(game, game->p_path, &(game->p));
	load_image(game, game->w_path, &(game->w));
}

void	start_mlx(t_game *game)
{
	game->map.total_size.x = (game->map.map_size.x + 1) * game->map.img_size.x;
	game->map.total_size.y = (game->map.map_size.y + 1) * game->map.img_size.y;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_solong("Could not initiate the first mlx thing", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.total_size.x,
			game->map.total_size.y, "So_Long");
	if (!game->win_ptr)
		error_solong("Could not make window", game);
	set_textures(game);
	display_map(game, 0, 0);
}
