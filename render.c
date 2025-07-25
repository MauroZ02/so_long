/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:47:21 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/25 22:04:24 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	char	**player;

	player = game->map->map[new_y][new_x];
	if (game->map->map[new_y][new_x] == '1')
		return ;
	else if (game->map->map[new_y][new_x] == 'C')
		game->counts->c = game->counts->c --;
	else if (game->map->map[new_y][new_x] == 'E' && game->counts->c > 0)
		return ;
	game->map->map[game->player_y][game->player_x] = '0';
	game->map->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	free_map(game->map->map_copy);
	game->map->map_copy = copy_map(game->map->map);
	render_map(game->mlx, game->win, game->map, game->sprites);
}

int	handle_keys(int keycode, void *param)
{
	t_game	*game;
	int		new_y;
	int		new_x;

	new_y = 0;
	new_x = 0;
	game = (t_game *)param;
	if (keycode == 65361)
		new_x - 1;
	else if (keycode == 65363)
		new_x + 1;
	else if (keycode == 65362)
		new_y - 1;
	else if (keycode == 65364)
		new_y + 1;
	else if (keycode == 65307)
		exit (0);
	else
		return (0);
	//ft_printf("Key pressed: %d\n", keycode);
	move_player(game->map, game->player_x + new_x, game->player_y + new_y);
	return (0);
}

int	handle_exit(void *param)
{
	(void)param;
	exit (0);
	return (0);
}

void	render_map(void *mlx, void *win, t_map *map, t_sprites *sprites)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map->map_copy[y])
	{
		while (map->map_copy[y][x])
		{
			if (map->map_copy[y][x] == '1')
				mlx_put_image_to_window(mlx, win, sprites->wall, x * SIZE, y * SIZE);
			else if (map->map_copy[y][x] == '0')
				mlx_put_image_to_window(mlx, win, sprites->floor, x * SIZE, y * SIZE);
			else if (map->map_copy[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, sprites->player, x * SIZE, y * SIZE);
			else if (map->map_copy[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, sprites->box, x * SIZE, y * SIZE);
			else if (map->map_copy[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, sprites->exit, x * SIZE, y * SIZE);
			x++;
		}
		x = 0;
		y++;
	}
}
