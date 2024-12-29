/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:15:13 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/18 08:38:08 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move(int y, int x, t_game *game)
{
	if (game->map.grid[y][x] == '1')
		return ;
	if (game->map.grid[y][x] == 'E' && game->map.c != 0)
		return ;
	if (game->map.grid[y][x] == 'E' && game->map.c == 0)
	{
		game->moves += 1;
		ft_printf("\rCounter of moves : %d", game->moves);
		ft_printf("\nBravo ! You finished the game with %d moves\n", game->moves);
		game_over(game);
	}
	if (game->map.grid[y][x] == 'C')
		game->map.c -= 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->f,
		game->map.player_pos.x * game->map.img_size.x,
		game->map.player_pos.y * game->map.img_size.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->p,
		x * game->map.img_size.x, y * game->map.img_size.y);
	game->map.grid[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.x = x;
	game->map.player_pos.y = y;
	game->moves += 1;
	ft_printf("\rCounter of moves : %d", game->moves);
}

int	end(t_game *game)
{
	game_over(game);
	return (0);
}

int	key_press(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		game_over(game);
	if (keysym == XK_w)
		player_move(game->map.player_pos.y - 1, game->map.player_pos.x, game);
	if (keysym == XK_a)
		player_move(game->map.player_pos.y, game->map.player_pos.x - 1, game);
	if (keysym == XK_s)
		player_move(game->map.player_pos.y + 1, game->map.player_pos.x, game);
	if (keysym == XK_d)
		player_move(game->map.player_pos.y, game->map.player_pos.x + 1, game);
	return (0);
}

void	handle_mlx(t_game *game)
{
	mlx_key_hook(game->win_ptr, &key_press, game);
	mlx_hook(game->win_ptr, 17, 0, &end, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	game;

	map_parse(argv[1], &game, argc);
	start_mlx(&game);
	handle_mlx(&game);
	return (0);
}
