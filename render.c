/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:47:21 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/27 01:42:47 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up_and_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprites->wall);
	mlx_destroy_image(game->mlx, game->sprites->floor);
	mlx_destroy_image(game->mlx, game->sprites->player);
	mlx_destroy_image(game->mlx, game->sprites->exit);
	mlx_destroy_image(game->mlx, game->sprites->box);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map->map_copy);
	free_map(game->map->map);
	free(game->map);
	free(game->sprites);
	free(game->counts);
	exit(0);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	char	target;

	target = game->map->map[new_y][new_x];
	if (game->map->map[new_y][new_x] == '1')
		return ;
	if (game->map->map[new_y][new_x] == 'C')
	{
		game->counts->c--;
		game->player_x = new_x;
		game->player_y = new_y;
		game->moves++;
		game->map->map[new_y][new_x] = '0';
	}
	if (target == 'E')
	{
		if (game->counts->c == 0)
			clean_up_and_exit(game);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves done:%d\n", game->moves);
	free_map(game->map->map_copy);
	game->map->map_copy = copy_map(game->map->map);
	render_map(game);
}

int	handle_keys(int keycode, void *param)
{
	t_game	*game;
	int		new_y;
	int		new_x;

	new_y = 0;
	new_x = 0;
	game = (t_game *)param;
	if (keycode == 65361 || keycode == 97)
		new_x = new_x - 1;
	else if (keycode == 65363 || keycode == 100)
		new_x = new_x + 1;
	else if (keycode == 65362 || keycode == 119)
		new_y = new_y - 1;
	else if (keycode == 65364 || keycode == 115)
		new_y = new_y + 1;
	else if (keycode == 65307)
		exit (0);
	else
		return (0);
	move_player(game, game->player_x + new_x, game->player_y + new_y);
	return (0);
}

int	handle_exit(t_game *game)
{
	clean_up_and_exit(game);
	return (0);
}

void	render_map(t_game *g)
{
	int		y;
	int		x;

	y = -1;
	while (g->map->map[++y])
	{
		x = -1;
		while (g->map->map[y][++x])
		{
			mlx_put_image_to_window(g->mlx, g->win, g->sprites->floor,
				x * SIZE, y * SIZE);
			if (g->map->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->sprites->wall,
					x * SIZE, y * SIZE);
			if (g->map->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->sprites->exit,
					x * SIZE, y * SIZE);
			if (g->map->map_copy[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->sprites->box,
					x * SIZE, y * SIZE);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->sprites->player,
		g->player_x * SIZE, g->player_y * SIZE);
}
// void	clean_up_and_exit(t_game *game)
// {
// 	free_map(game->map->map_copy);
// 	free_map(game->map->map);
// 	free(game->map);
// 	free(game->sprites);
// 	free(game->counts);
// 	mlx_destroy_window(game->mlx, game->win);
// 	exit(0);
// }
// int	handle_exit(void *param)
// {
// 	(void)param;
// 	exit (0);
// 	return (0);
// }

// void	render_map(void *mlx, void *win, t_map *map, t_sprites *sprites)
// {
// 	int		y;
// 	int		x;

// 	y = 0;
// 	x = 0;
// 	while (map->map_copy[y])
// 	{
// 		while (map->map_copy[y][x])
// 		{
// 			if (map->map_copy[y][x] == '1')
// 				mlx_put_image_to_window(mlx, win, sprites->wall, x * SIZE, y * 
//SIZE);
// 			else if (map->map_copy[y][x] == '0')
// 				mlx_put_image_to_window(mlx, win, sprites->floor, x * SIZE, y * 
//SIZE);
// 			else if (map->map_copy[y][x] == 'P')
// 				mlx_put_image_to_window(mlx, win, sprites->player, x * SIZE, y 
//* SIZE);
// 			else if (map->map_copy[y][x] == 'C')
// 				mlx_put_image_to_window(mlx, win, sprites->box, x * SIZE, y *
// SIZE);
// 			else if (map->map_copy[y][x] == 'E')
// 				mlx_put_image_to_window(mlx, win, sprites->exit, x * SIZE, y * 
//SIZE);
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }